class Solution:
    def calculate(self, s: str) -> int:
        res = 0
        pre_op = "+"
        s += "+"
        num = 0
        stack = []
        for i in s:
            #print(i)
            #print(num,res,pre_op,stack)
            if i.isdigit():
                num = num*10 + int(i)
            elif i == " ":
                continue
            elif i in ["+","-"]:
                if pre_op == "+":
                    res += num
                else:
                    res -= num
                pre_op = i
                num = 0
            elif i == "(":
                stack.append(res)
                stack.append(pre_op)
                res = 0
                num = 0
                pre_op = "+"
            elif i == ")":
                if pre_op == "+":
                    res += num
                else:
                    res -= num
                if stack[-1] == "+":
                    #res += num
                    stack.pop()
                    res += stack.pop()
                elif stack[-1] == "-":
                   # res -= num
                    stack.pop()
                    res = stack.pop() - res
                num = 0
                pre_op = "+"
        return res 