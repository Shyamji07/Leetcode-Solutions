/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int n;
	
    int peakFinder(int left, int right, int target, MountainArray &mountainArr) {        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midElement = mountainArr.get(mid);
            int prevElement =  mid - 1 < 0 ? INT_MIN : mountainArr.get(mid - 1);
            int nextElement = mid + 1 >= n ? INT_MIN : mountainArr.get(mid + 1);
            
            if (midElement > prevElement and midElement > nextElement)
                return mid;
            
            if (midElement > prevElement)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1; // trivial
    }
    
    int binarySearch(int left, int right, int target, MountainArray &mountainArr, bool ascendingFlag) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midElement = mountainArr.get(mid);
            
            if (midElement == target)
                return mid;
            
            if (midElement < target)
                ascendingFlag ? left = mid + 1 : right = mid - 1;
            else
                ascendingFlag ? right = mid - 1 : left = mid + 1;
        }
        
        return -1;
    }
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int left = 0, right = n - 1;
        
        // find the peak
        int peakPosition = peakFinder(left, right, target, mountainArr);
        
        // search in left slope first
        int result = binarySearch(left, peakPosition, target, mountainArr, true);
        
        // if result was not found in the left slope, search in the right slope
        return result != -1 ? result : binarySearch(peakPosition, right, target, mountainArr, false);
    }
};