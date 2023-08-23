class Solution:
    def trap(self, height: List[int]) -> int:
        curr_max = 0
        max_left = [curr_max:=max(curr_max, h) for h in height]
        curr_max = 0
        max_right = [curr_max:=max(curr_max,h)for h in reversed(height)]
        max_right.reverse()
        return sum([min(max_left[i],max_right[i])-height[i] for i in range(len(height))])