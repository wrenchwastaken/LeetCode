impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let n = nums.len();
        let (mut l, mut r) = (0, n);

        while l < r {
            let m = l + (r - l) / 2;
            if nums[m] < target {
                l = m + 1;
            } else {
                r = m;
            }
        }

        if l < n && nums[l] == target { 
            l as _ 
        } else { 
            -1 
        }
    }
}