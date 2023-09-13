class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        n = len(items)
        result = []
        for i in range(1,n):
            items[i][1] = max(items[i][1],items[i-1][1])
        for q in queries:
            l = 0
            r = n-1
            while l<=r:
                m = (l+r)//2
                p,b = items[m]
                if p > q:
                    r = m-1
                else:
                    l = m+1
            result.append(items[r][1] if r>=0 else 0)
        return result