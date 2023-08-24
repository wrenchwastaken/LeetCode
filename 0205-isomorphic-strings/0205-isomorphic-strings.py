class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map1 = []
        map2 = []
        for i in s:
            map1.append(s.index(i))
        for j in t:
            map2.append(t.index(j))
        if map1 == map2:
            return True
        return False