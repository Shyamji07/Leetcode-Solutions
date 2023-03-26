class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        answer = []
        N = len(nums)
    
        arr = [0]
        for n in nums:
            arr.append(arr[-1] + n)
            
        for q in queries:
            index = 0
            i = bisect.bisect_left(nums, q)
            left = arr[i]
            temp = q * (i)
            index += abs(temp - left)
            right = arr[-1] - arr[i]
            temp = q * (N - i)
            index += abs(temp - right)
            
            answer.append(index)
        
        return answer
