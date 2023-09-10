class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def dfs(start,path,result):
            result.append(path)
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i-1]:
                    continue
                dfs(i+1,path+[nums[i]],result)
        nums.sort()
        result = []
        dfs(0,[],result)
        return result
        
