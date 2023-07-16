class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mapp = [0] * 26
        for c in s1:
            mapp[ord(c) - 97] += 1
        i, j, count_chars = 0, 0, len(s1)
        while j < len(s2):
            if mapp[ord(s2[j]) - 97] > 0:   
                count_chars -= 1
            mapp[ord(s2[j]) - 97] -= 1
            j += 1
            if count_chars == 0:
                return True
            if j - i == len(s1):
                if mapp[ord(s2[i]) - 97] >= 0:
                    count_chars += 1
                mapp[ord(s2[i]) - 97] += 1
                i += 1
                
        return False