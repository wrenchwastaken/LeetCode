class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lh(nums,target):
            low=0
            high=len(nums)-1
            while low<=high:
                mid=low+(high-low)//2
                if nums[mid]<target:
                    low=mid+1
                else:
                    high=mid-1
            return low
        def rh(nums,target):
            low=0
            high=len(nums)-1
            while low<=high:
                mid=low+(high-low)//2
                if nums[mid]<=target:
                    low=mid+1
                else:
                    high=mid-1
            return high
        lhs=lh(nums,target)
        rhs=rh(nums,target)
        if lhs<=rhs:
            return [lhs,rhs]
        return [-1,-1]



                  
        
        
        