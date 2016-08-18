# Binary Search

**Problem Statement**:Given a sorted array, you have to tell whether an element lies in the array or not.  
Binary search is a technique which utilizes the additional information about the ordering of the elements to reduce the number of elements that needs to be compared with the target element, by recursively dividing the array into smaller ranges(half of the range in previous step) till we get an empty range.

pseudo-code.
```
    def BinarySearch(A, key, range):
        if range.start >= range.end:
            return false; # degenerate range
        mid = range.start + (range.end - range.start)/2; #find the mid point 
        if A[mid] == key:
           return true;
         else if A[mid] > key:
           # The element lies in the first half of the range
           return BinarySearch(A, key, [range.first, mid))
         else:
            # Element lies in second half of range
            return BinarySearch(A, key, [mid+1, range.second))
```
Lets convince ourselves why this works.
At each step in the iteration we are picking the middle element and based on relative ordering of element in the middle lets say `A[mid]` with the `key`  we are eliminating one half of the array.
Formally:
For any A which meets:

`A[i] > A[j] Iff i > j`  # sorted property

`A[mid] > key =>  A[j] > key ∀  j > =  mid ` 

So we can safely eliminate all elements 
**including and beyond including mid**.

Similarly 

`A[mid] < key => A[j] < key ∀ j<=mid`

So we can safely eliminate all elements **from beginning including mid**

Obviously if at any point `A[mid] == key` we know that the element exists


Notice that Binary Search would work for any sorted sequence and not necessarily an array. This observation allows us to expand binary search to any **monotonically increasing/decreasing function**  
For example if you have to find whether a number is  `perfect square` or not we can modify our logic as:
```
def IsPerfectSquare(x, [low, high)):
    if high <= low:
       return false;
    mid = low + (high - low)/2
    key = pow(mid, 2);
    if key == x:
       return true;
    if key > x:
       return IsPerfectSquare(x, [low, mid));
     else:
       return IsPerfectSquare(x, (mid, high]);
```

Notice that the `sorted array` gets replaced by `pow` function which is **monotinically increasing**