class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        st1 = Counter(ransomNote)
        st2 = Counter(magazine)
        if st1 & st2 == st1:
            return True
        return False