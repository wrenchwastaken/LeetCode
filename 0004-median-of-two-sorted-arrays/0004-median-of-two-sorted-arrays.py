class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1
        
        total = len(nums1) + len(nums2)
        half = total // 2
        
        l, r = 0, len(nums1) - 1
        while True:
            i = (l + r) // 2    # for nums1
            j = half - i - 2    # for nums2
            
            left_nums1 = nums1[i] if i >= 0 else float("-inf")
            right_nums1 = nums1[i+1] if (i + 1) < len(nums1) else float("inf")
            
            left_nums2 = nums2[j] if j >= 0 else float("-inf")
            right_nums2 = nums2[j+1] if (j + 1) < len(nums2) else float("inf")
            
            if left_nums1 <= right_nums2 and left_nums2 <= right_nums1:
                
                if total % 2:
                    return min(right_nums1, right_nums2)
                else:
                    return (max(left_nums1, left_nums2) + min(right_nums1, right_nums2)) / 2
            
            elif left_nums1 > right_nums2:
                r = i - 1
            else:
                l = i + 1