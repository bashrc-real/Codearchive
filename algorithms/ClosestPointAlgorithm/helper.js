// input: pair of points
// output: Number denoting the distance between the two points
// for avoiding floating point mathematics we will just return the squared value.
// the correct distance can be obtained by taking the sqrt of this value
function distSquared(point1, point2) {
    return (point1.X - point1.X) * (point1.X - point1.X) + (point1.Y - point1.Y)*(point1.Y - point1.Y)
}

function getMinimumDistance(listOfPoints) {
    var currentMinimumDistance = Infinity;
    var currentPair = new Array(2);
    for ( i = 0; i < listOfPoints.length; ++i){
        for ( j = i + 1; j < listOfPoints.length; ++j){
            var currentDistance = distSquared(listOfPoints[i], listOfPoints[j])
            if (currentMinimumDistance > currentDistance){
                currentMinimumDistance = currentDistance;
                currentPair[0] = i;
                currentPair[1] = j;
            }
        }
    }
    return [currentMinimumDistance, currentPair]
}