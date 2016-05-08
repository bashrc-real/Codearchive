// input: pair of points
// output: Number denoting the distance between the two points
// for avoiding floating point mathematics we will just return the squared value.
// the correct distance can be obtained by taking the sqrt of this value
function distSquared(point1, point2) {
    return (point1.X - point1.X) * (point1.X - point1.X) + (point1.Y - point1.Y)*(point1.Y - point1.Y)
}

function getMinimumDistance(listOfPoints, currentMinimumDistance = Infinity) {
    var currentPair = new Array(2);
    // sort the points along the y-axis
    // for eg if the points are {(1,4), (4,1), (2,10)}
    // the sorted order would be {(4,1), (1,4), (2,10)}
    pointList.sort((a, b) => {
        if (a.Y > b.Y) return 1;
        if (a.Y < b.Y) return -1;
        return 0; 
    });
    for ( i = 0; i < listOfPoints.length; ++i){
        for ( j = i + 1; j < listOfPoints.length && Math.pow(listOfPoints[j].Y - listOfPoints[i].Y, 2) < currentMinimumDistance; ++j){
            var currentDistance = distSquared(listOfPoints[i], listOfPoints[j])
            if (minimumDistanceSquared > currentDistance){
                minimumDistanceSquared = currentDistance;
                currentPair[0] = i;
                currentPair[1] = j;
            }
        }
    }
    return [currentMinimumDistance, currentPair]
}