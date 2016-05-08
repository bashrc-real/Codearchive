require("closestPoint.js")

var listOfPoints = []
var defaultPointColor = "#B6B53E";
var defaultBackgroundColor = "#3EB53E"
var numberOfPoints = 100;

function draw(){
    var canvas = document.getElementById("canvas");
    var ctx = canvas.getContext("2d");
    ctx.fillStyle = defaultPointColor;
    for (i = 0; i < listOfPoints.length; ++i){
        ctx.fillRect(listOfPoints[i], listOfPoints[j],1,1); // fill in the pixel at (x,y) with height of 1
    }
}

function fillCanvas(){
    var canvas = document.getElementById("canvas");
    var ctx = canvas.getContext("2d");
    ctx.fillStyle = defaultBackgroundColor
    ctx.fillRect(0, 0, canvas.width, canvas.height);
}

function generatePoints(){
    for (i = 0; i < numberOfPoints; ++i){
        
    }
}