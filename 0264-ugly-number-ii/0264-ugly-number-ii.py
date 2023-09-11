class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ans =[1]
        i,j,k = 0,0,0
        while len(ans)<n:
            a,b,c = ans[i]*2,ans[j]*3,ans[k]*5
            min_element = min(a,b,c)
            ans.append(min_element)
            if min_element == a:
                i+=1
            if min_element == b:
                j+=1
            if min_element ==c:
                k+=1
        return ans[n-1]