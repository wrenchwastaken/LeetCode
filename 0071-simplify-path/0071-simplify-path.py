class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        p = path.split("/")
        for i in p:
            if i =="..":
                if stack:
                    stack.pop()
            elif i not in ("","."):
                stack.append(i)
        return "/" + "/".join(stack)