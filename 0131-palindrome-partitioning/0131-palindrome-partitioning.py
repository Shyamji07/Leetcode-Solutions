class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palindrome(s):
            i = 0
            j = len(s)-1
            while i < j:
                if s[i] != s[j]:
                    return False
                i+=1
                j-=1
            return True

        def partition(s, path, result):
            if len(s) == 0:
                result.append([i for i in path])
                return
            string = ""
            for i in range(len(s)):
                string += s[i]
                if is_palindrome(string):
                    path.append(string)
                    partition(s[i+1:], path, result)
                    path.pop()
        final = []
        partition(s, [], final)
        return final