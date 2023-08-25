import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i!='+' and i!='-' and i!='*' and i!='/':
                stack.append(int(i,10))
                
            else:
                if len(stack)==1:
                    return stack[0]
                a = stack[-1]
                b = stack[-2]
                
                if i=='+':
                    ans = b+a
                elif i=='-':
                    ans = b-a
                elif i=='*':
                    ans = b*a
                else:
                    ans = int(b/a)
                stack.pop()
                stack.pop()
                stack.append(ans)
        return stack[0]