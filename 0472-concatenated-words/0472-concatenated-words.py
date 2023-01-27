class Solution:
    def findAllConcatenatedWordsInADict(self, arr: List[str]) -> List[str]:
        st = set(arr)
        ans = set()
        def dfs(s):
            if not s: return True
            temp = ''
            for i in range(len(s)):
                temp += s[i]
                if temp in st:
                    if dfs(s[i + 1:]): return True

            return False
        for word in st:
            st.remove(word)
            if dfs(word): ans.add(word)
            st.add(word)
        return ans