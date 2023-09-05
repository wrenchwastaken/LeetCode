class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = []
        opened = 0
        for i in s:
            if i == "(" and opened > 0:
                result.append(i)
            if i == ")" and opened > 1:
                result.append(i)
            opened += 1 if i == "(" else -1
        return "".join(result)
        