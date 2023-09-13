class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:

        """

        1 7 5
        2 3 5

        1 4 0 = 5 (diff1)
        -
        1 1 5
        2 3 5

        1 2 0 = 3 (diff2)

        diff2 = diff1 - abs(old_num1 - num2) + abs(new_num2 - num2)

        """

        n = len(nums1)
        mod = 10 ** 9 + 7
        nums1_sorted = sorted(nums1)

        def find_closest(target):
            l = -1
            r = n
            while l + 1 < r:
                m = (l + r) // 2
                if nums1_sorted[m] < target:
                    l = m
                else:
                    r = m

            # avoid using l == -1 and r == n
            l = max(l, 0)
            r = min(r, n-1)
            # find closest value to target
            if abs(target - nums1_sorted[l]) < abs(target - nums1_sorted[r]):
                return nums1_sorted[l]
            return nums1_sorted[r]


        ans = float('inf')
        def solve():
            nonlocal ans

            # initial abs diff without replacement
            abs_diff = 0
            for i in range(n):
                abs_diff += abs(nums1[i]-nums2[i])
            ans = min(ans, abs_diff)

            for i in range(n):
                closest = find_closest(nums2[i])
                old_value = nums1[i]

                # update abs diff
                new_abs_diff = abs_diff - abs(old_value - nums2[i]) + abs(closest - nums2[i])
                ans = min(ans, new_abs_diff)

                # bring back old value
                nums1[i] = old_value


        solve()
        return ans % mod