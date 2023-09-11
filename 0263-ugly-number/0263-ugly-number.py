class Solution:
    def isUgly(self, n: int) -> bool:
        if n<1:
            return False
        multiple=2*3*5
        return (multiple**20)%n==0

    
