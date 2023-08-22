class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        max_reach=0
        steps=0
        last_jump=0
        for i in range(n-1):
            max_reach=max(max_reach,i+nums[i])
            if i==last_jump:
                last_jump = max_reach
                steps = steps + 1
        return steps   