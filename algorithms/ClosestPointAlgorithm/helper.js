// input: pair of points
// output: Number denoting the distance between the two points
// for avoiding floating point mathematics we will just return the squared value.
// the correct distance can be obtained by taking the sqrt of this value
function distSquared(point1, point2) {
    return (point1.X - point2.X) * (point1.X - point2.X) + (point1.Y - point2.Y)*(point1.Y - point2.Y);
}

function getMinimumDistance(listOfPoints, currentMinimumDistance) {
    if (!currentMinimumDistance){
        currentMinimumDistance = Infinity;
    }
    var currentPair = [null, null];
    // sort the points along the y-axis
    // for eg if the points are {(1,4), (4,1), (2,10)}
    // the sorted order would be {(4,1), (1,4), (2,10)}
    listOfPoints.sort((a, b) => {
        if (a.Y > b.Y) return 1;
        if (a.Y < b.Y) return -1;
        return 0; 
    });
    for ( i = 0; i < listOfPoints.length; ++i){
        for ( j = i + 1; j < listOfPoints.length && Math.pow(listOfPoints[j].Y - listOfPoints[i].Y, 2) < currentMinimumDistance; ++j){
            var currentDistance = distSquared(listOfPoints[i], listOfPoints[j])
            if (currentMinimumDistance > currentDistance){
                currentMinimumDistance = currentDistance;
                currentPair[0] = listOfPoints[i];
                currentPair[1] = listOfPoints[j];
            }
        }
    }
    return [currentMinimumDistance, currentPair]
}