# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def rightSideView(self, root: TreeNode) -> List[int]:
        result = []
    
        def get_result(root,level):
            if not root:
                return
            if level==len(result):
                result.append(root.val)
            get_result(root.right,level+1)
            get_result(root.left,level+1)
        
        get_result(root,0)
        return result
        