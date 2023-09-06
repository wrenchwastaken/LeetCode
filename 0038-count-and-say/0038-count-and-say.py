class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        previous = self.countAndSay(n-1)
        result = ""
        count = 1
        digit = previous[0]
        for i in range(1, len(previous)):
            if previous[i] == digit:
                count += 1
            else:
                result += str(count) + digit
                count = 1
                digit = previous[i]
        result += str(count) + digit
        return result
        