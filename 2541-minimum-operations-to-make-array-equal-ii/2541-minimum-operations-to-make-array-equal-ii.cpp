class Solution:
    def minOperations(self, arr1: List[int], arr2: List[int], k: int) -> int:
        abss = [0]*len(arr1)
        if arr1==arr2:
            return 0
        for i in range(len(arr1)):
            abss[i] = arr1[i]-arr2[i]

        if sum(abss)!=0:
            return -1
        ans = 0
        for i in abss:
            if i>0:
                ans+=i

        if k!=0 and ans%k==0:
            return ans//k
        else:
            return -1