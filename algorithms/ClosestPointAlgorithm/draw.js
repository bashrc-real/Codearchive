var defaultPointColor = "#FF0000";
var defaultBackgroundColor = "#DDDDDD"
var lineColor = "#EEDDEE";
var numberOfPoints = 100;
var pixelWidth = 4;

function drawLine(context, p1, p2){
    var currentColor = context.fillStyle;
    context.fillStyle = lineColor;
    context.beginPath();
    context.moveTo(p1.X, p1.Y);
    context.lineTo(p2.X, p2.Y);
    context.stroke();
    context.fillStyle = currentColor;
}

function draw(){
    var canvas = document.getElementById("canvas");
    var listOfPoints = generatePoints(document.getElementById("pointCount").value, canvas.width, canvas.height);
    var ctx = canvas.getContext("2d");
    fillCanvas();
    ctx.fillStyle = defaultPointColor;
    for (i = 0; i < listOfPoints.length; ++i){
        ctx.fillRect(listOfPoints[i].X - Math.floor(pixelWidth/2) , listOfPoints[i].Y - Math.floor(pixelWidth/2), pixelWidth, pixelWidth); // fill in the pixel at (x,y) with height of 2
    }
    point = closestPoint(listOfPoints);
    drawLine(ctx, point[0], point[1]);
}

function fillCanvas(){
    var canvas = document.getElementById("canvas");
    var ctx = canvas.getContext("2d");
    ctx.fillStyle = defaultBackgroundColor
    ctx.fillRect(0, 0, canvas.width, canvas.height);
}

function generatePoints(N, maxX, maxY){
    randomPoints = [];
    for (i = 0; i < N; ++i){
        randomPoints.push({X : Math.floor(Math.random() * maxX), Y : Math.floor(Math.random() * maxY)});
    }
    return randomPoints;
}