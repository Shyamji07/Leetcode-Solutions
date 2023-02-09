class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        arr = [set() for _ in range(26)]
        for idea in ideas:
            arr[ord(idea[0]) - ord('a')].add(idea[1:])
        
        count = 0
        for i in range(25):
            for j in range(i + 1, 26):
                temp = len(arr[i] & arr[j]) 
                count += 2 * (len(arr[i]) - temp) * (len(arr[j]) - temp)
                
        return count