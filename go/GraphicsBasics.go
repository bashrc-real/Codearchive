package main

import (
	"fmt"
	"log"
	"runtime"
	"strings"

	"github.com/go-gl/gl/v2.1/gl"
	"github.com/go-gl/glfw/v3.1/glfw"
)

var vertexShaderSource = `
    #version 410
    in vec3 vp;
    void main() {
        gl_Position = vec4(vp, 1.0);
    }
` + "\x00"

var fragmentShaderSource = `
    #version 410
    out vec4 frag_colour;
    void main() {
        frag_colour = vec4(0.6, 0.6, 1, 1);
    }
` + "\x00"

const (
	WindowWidth  = 500
	WindowHeight = 500
)

type Color struct {
	red   float32
	blue  float32
	green float32
	alpha float32
}

var fillColor = Color{0.30, 0.10, 0.40, 1.0}
var points = []float32{
	0.5, 0.5, 0,
	-0.5, -0.5, 0,
	0.5, -0.5, 0}

func main() {
	runtime.LockOSThread()

	window := initGlfw()
	defer glfw.Terminate()
	program := initOpenGL()
	vertexArray := setupVertexBuffers(points)
	for !window.ShouldClose() {
		draw(vertexArray, window, program)
	}
}

func compileShader(source string, shaderType uint32) (uint32, error) {
	shader := gl.CreateShader(shaderType)

	csources, free := gl.Strs(source)
	gl.ShaderSource(shader, 1, csources, nil)
	free()
	gl.CompileShader(shader)

	var status int32
	gl.GetShaderiv(shader, gl.COMPILE_STATUS, &status)
	if status == gl.FALSE {
		var logLength int32
		gl.GetShaderiv(shader, gl.INFO_LOG_LENGTH, &logLength)

		log := strings.Repeat("\x00", int(logLength+1))
		gl.GetShaderInfoLog(shader, logLength, nil, gl.Str(log))

		return 0, fmt.Errorf("failed to compile %v: %v", source, log)
	}

	return shader, nil
}

// initOpenGL initializes OpenGL and returns an intiialized program.
func initOpenGL() uint32 {
	if err := gl.Init(); err != nil {
		panic(err)
	}
	version := gl.GoStr(gl.GetString(gl.VERSION))
	log.Println("OpenGL version", version)

	vertexShader, err := compileShader(vertexShaderSource, gl.VERTEX_SHADER)
	if err != nil {
		panic(err)
	}
	fragmentShader, err := compileShader(fragmentShaderSource, gl.FRAGMENT_SHADER)
	if err != nil {
		panic(err)
	}

	prog := gl.CreateProgram()
	gl.AttachShader(prog, vertexShader)
	gl.AttachShader(prog, fragmentShader)
	gl.LinkProgram(prog)
	return prog
}

func setupVertexBuffers(points []float32) uint32 {
	var vbo uint32
	// why is there no GenBuffer equivalent?
	// Similarly why is there no GenVertexArray equivalent
	gl.GenBuffers(1, &vbo)
	gl.BindBuffer(gl.ARRAY_BUFFER, vbo)
	// find of sizeof equivalent in go
	gl.BufferData(gl.ARRAY_BUFFER, 4*len(points), gl.Ptr(points), gl.STATIC_DRAW)
	var vertexArray uint32
	gl.GenVertexArrays(1, &vertexArray)
	gl.BindVertexArray(vertexArray)
	gl.EnableVertexAttribArray(0)
	gl.VertexAttribPointer(0, int32(len(points)/3), gl.FLOAT, false, 0, nil)
	return vertexArray
}

// swapping the clearColor and Clear doesn't make any difference
func draw(vertexArray uint32, window *glfw.Window, program uint32) {
	gl.ClearColor(fillColor.red, fillColor.blue, fillColor.green, fillColor.alpha)
	gl.Clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)
	gl.UseProgram(program)
	gl.BindVertexArray(vertexArray)
	gl.DrawArrays(gl.TRIANGLES, 0, int32(len(points)/3))
	glfw.PollEvents()
	window.SwapBuffers()
}

// initGlfw initializes glfw and returns a Window to use.
func initGlfw() *glfw.Window {
	if err := glfw.Init(); err != nil {
		panic(err)
	}

	glfw.WindowHint(glfw.Resizable, glfw.False)
	glfw.WindowHint(glfw.ContextVersionMajor, 4) // OR 2
	glfw.WindowHint(glfw.ContextVersionMinor, 1)
	glfw.WindowHint(glfw.OpenGLProfile, glfw.OpenGLCoreProfile)
	glfw.WindowHint(glfw.OpenGLForwardCompatible, glfw.True)

	window, err := glfw.CreateWindow(WindowWidth, WindowHeight, "Conway's Game of Life", nil, nil)
	if err != nil {
		panic(err)
	}
	window.MakeContextCurrent()

	return window
}
