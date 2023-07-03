var findClosestElements = function (arr, k, x) {
  let leftPointer = 0;
  let rightPointer = arr.length - 1;
  while (rightPointer - leftPointer >= k) {
    // a-x <= b-x (Comparison Law at the Question)
    if (Math.abs(arr[leftPointer] - x) <= Math.abs(arr[rightPointer] - x)) rightPointer--;
    else leftPointer++;
  }
  return arr.slice(leftPointer, rightPointer + 1);
};