class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        st1 = Counter(s)
        st2 = Counter(t)
        if st1 == st2:
            return True
        return False