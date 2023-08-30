class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        v = ["a","e","i","o","u"]
        val = []
        pos = []
        for i in range(len(s)):
            if s[i].lower() in v:
                val.append(s[i])
                pos.append(i)
        val = val[::-1]
        for i in range(len(pos)):
            s[pos[i]] = val[i]
        return ''.join(s)
