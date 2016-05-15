// Input: list of points in 2-D space
// Return : tuple with two items denoting the index of the two closest points
function closestPoint(pointList) {
    
    // sort the points along the x-axis
    // for eg if the points are {(1,4), (4,1), (2,10)}
    // the sorted order would be {(1,4), (2,10), (4,1)}
    pointList.sort((a, b) => {
        if (a.X > b.X) return 1;
        if (a.X < b.X) return -1;
        return 0; 
    });
    return compute(pointList, 0, pointList.length)[1];    
}

// Divide the 2-D space recursively into smaller regions
// Once the region becomes small enough, do a brute force on the region
// to find the min. reduce the combined min at each region level and keep reducing back at each level
// till the entire region is covered.
// Now we will have a local minima, lets say d. Find all points in the current region which are closer than d.
// These will be points near the mid point boundary seperating two regions. Do a brute force on them to find the global minima
function compute(pointsInCurrentRegion, start , end){
    var elemCount = end - start;
    if (elemCount <= 3){
        return getMinimumDistance(pointsInCurrentRegion);
    }
    var mid = start + Math.floor(elemCount/2);
    var midPoint = pointsInCurrentRegion[mid];
    var leftDistance = compute(pointsInCurrentRegion, start, mid);
    var rightDistance = compute(pointsInCurrentRegion, start + mid, end);
    var d;
    if (leftDistance[0] < rightDistance[0]){
        d = leftDistance;
    }else{
        d = rightDistance;
    }
    strip = [];
    for (i = 0; i < elemCount; i++){
        if (Math.abs(pointsInCurrentRegion[start + i].X - midPoint.X) < d[0])
            strip.push(pointsInCurrentRegion[start + i]);
    }
    var minDistanceInMiddleStrip = getMinimumDistance(strip, d[0]);
    if (d[0] <= minDistanceInMiddleStrip[0]){
        return d;
    }else{
        return minDistanceInMiddleStrip;
    }
}
