class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phoneMap  = {2:'abc', 3:'def', 4:'ghi', 5:'jkl', 6:'mno', 7:'pqrs', 8:'tuv', 9:'wxyz'}
        combinations = []
        if len(digits) != 0:
            self.f(0,digits,combinations,phoneMap,'')
        return combinations
    def f(self,i,digits,combinations,phoneMap,current):
        if len(current) == len(digits):
            combinations.append(current)
            return
        for j in range(len(phoneMap[int(digits[i])])):
            self.f(i+1,digits,combinations,phoneMap,current+phoneMap[int(digits[i])][j])