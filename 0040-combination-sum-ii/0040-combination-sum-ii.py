class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        def dfs(j,path,current):
            if current > target:
                return 
            if current == target:
                ans.append(path)
                return
            for i in range(j, len(candidates)):
                if i > j and candidates[i] == candidates[i-1]:
                    continue
                dfs(i+1,path+[candidates[i]],current+candidates[i])
        dfs(0,[],0)
        return ans