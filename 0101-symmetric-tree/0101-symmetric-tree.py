# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isSame(root.left,root.right)
    def isSame(self,leftroot,rightroot):
        if leftroot == None and rightroot == None:
            return True
        elif leftroot == None or rightroot == None:
            return False
        elif leftroot.val != rightroot.val:
            return False
        else:
            return self.isSame(leftroot.left, rightroot.right) and self.isSame(leftroot.right, rightroot.left)
        
        