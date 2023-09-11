class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(counter,path):
            if len(path) == len(nums):
                res.append(path)
                return
            for i in counter:
                if counter[i]:
                    counter[i] -= 1
                    dfs(counter,path+[i])
                    counter[i] += 1
        dfs(Counter(nums),[])
        return res