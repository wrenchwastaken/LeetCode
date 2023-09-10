class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        n = len(candidates)
        def dfs(current,current_sum,i):
            if current_sum > target:
                return 
            if current_sum == target:
                ans.append(current)
            for i in range(i,n):
                dfs(current+[candidates[i]],current_sum + candidates[i],i)
        dfs([],0,0)
        return ans