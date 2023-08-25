# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.root_index = {}
        self.index = 0
        for i,num in enumerate(inorder):
            self.root_index[num] = i
        
        def construct(left,right):
            if left > right:
                return None
            root = preorder[self.index]
            i = self.root_index[root]
            self.index += 1
            head = TreeNode(root)
            head.left = construct(left,i - 1)
            head.right = construct(i + 1, right)
            return head
        
        n = len(preorder) - 1
        return construct(0,n)
        