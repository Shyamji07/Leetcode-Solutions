class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.result =[]
        self.helper([],1,k,n)
        return self.result
    
    def helper(self,path,start,k,target):
        
        if k ==0 and target==0:
            self.result.append(path)
            return 
        
        if k == 0 or target <= 0:
            return
        
        for i in range(start,10):
            self.helper(path+[i],i+1,k-1,target-i)