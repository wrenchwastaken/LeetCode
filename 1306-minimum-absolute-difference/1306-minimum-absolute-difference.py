class Solution:
    def minimumAbsDifference(self, arr):
        # Step 1: Sort the input array
        arr.sort()
        
        # Step 2: Initialize variables to keep track of the minimum absolute difference
        min_diff = float('inf')
        result = []
        
        # Step 3: Iterate through the sorted array and find the minimum difference
        for i in range(len(arr) - 1):
            diff = arr[i+1] - arr[i]
            
            # Step 4: If the current difference is smaller than the minimum, update the minimum
            if diff < min_diff:
                min_diff = diff
                result = [[arr[i], arr[i+1]]]
            
            # Step 5: If the current difference is equal to the minimum, add it to the result
            elif diff == min_diff:
                result.append([arr[i], arr[i+1]])
        
        # Step 6: Return the result containing pairs with the minimum absolute difference
        return result

