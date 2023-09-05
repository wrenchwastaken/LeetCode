class Solution:
    def reverseWords(self, s: str) -> str:
        rt = s.split()
        rt.reverse()
        return " ".join(rt)
        