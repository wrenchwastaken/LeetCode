class Solution:
    def isPalindrome(self, s: str) -> bool:
        new = "".join(c for c in s.lower() if c.isalnum())
        return new == new[::-1]