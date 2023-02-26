class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) -1
        
        while(low<=high):
            mid=(low+high)//2
            if(nums[mid] == target):
                return mid
            elif nums[low] <= nums[mid]:
                if(target >= nums[low] and target < nums[mid]):
                    high = mid -1
                else:
                    low = mid +1
            elif nums[mid] < nums[high]:
                if(nums[mid] < target and nums[high] >= target):
                    low = mid+1
                else:
                    high = mid -1;
        return -1
                
                
                