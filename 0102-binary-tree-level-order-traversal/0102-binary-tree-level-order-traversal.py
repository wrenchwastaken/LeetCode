class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        
        def bfs(root, level):
            if root is None:
                return  # If the node is None, return without adding anything to the answer
            
            # Check if the length of 'ans' is greater than 'level'
            if len(ans) > level:
                ans[level].append(root.val)
            else:
                ans.append([root.val])
            
            # Recursively call bfs for the left and right children with an incremented level
            bfs(root.left, level + 1)
            bfs(root.right, level + 1)
        
        bfs(root, 0)  # Start the DFS at level 0
        return ans
