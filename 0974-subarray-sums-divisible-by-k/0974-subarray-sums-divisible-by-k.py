class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        pref = [0] * len(nums)
        pref[0] = nums[0]
        for i in range(1, len(nums)):
            pref[i] = pref[i-1] + nums[i]
        
        m = [0] * k
        m[0] = 1
        ans = 0
        for x in pref:
            if x < 0:
                x = (x % k + k) % k
            m[x % k] += 1
        # n choose 2
        for x in m:
            ans += x * (x - 1) // 2
        return ans
