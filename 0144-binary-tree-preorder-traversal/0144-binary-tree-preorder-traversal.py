# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def preorder(root,ans):
            if not root:
                return None
            ans.append(root.val)
            preorder(root.left,ans)
            preorder(root.right,ans)
        preorder(root,ans)
        return ans