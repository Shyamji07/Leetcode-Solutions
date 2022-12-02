class Solution:
    def closeStrings(self, s1: str, s2: str) -> bool:
        return Counter(Counter(s1).values()) == Counter(Counter(s2).values()) \
               and set(s1) == set(s2)