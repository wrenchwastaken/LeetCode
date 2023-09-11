class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        result =[]
        for i in range(len(nums)):
            for rest in self.permute(nums[:i]+nums[i+1:]):
                result.append([nums[i]]+rest)
        return result