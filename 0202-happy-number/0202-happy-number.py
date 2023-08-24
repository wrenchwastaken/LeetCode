class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        while n!=1:
            num = sum([int(i)**2 for i in str(n)])
            if num in visited:
                return False
            n = num
            visited.add(n)
        return True
        