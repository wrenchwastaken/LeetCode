class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        r = s.split()
        return len(r[-1])