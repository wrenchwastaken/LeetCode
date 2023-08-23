class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(needle)
        h = len(haystack)
        for i in range(h-n+1):
            for j in range(n):
                if needle[j] != haystack[i+j]:
                    break
                if j==n-1:
                    return i
        return -1