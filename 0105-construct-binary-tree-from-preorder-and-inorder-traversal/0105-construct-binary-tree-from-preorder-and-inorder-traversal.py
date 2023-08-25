# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        tree = None
        
        #check if the root exists in inorder
        if len(preorder) and preorder[0] in inorder:
            #find the root index
            root_index =inorder.index(preorder[0])
            #make the root node
            tree = TreeNode(val=inorder[root_index])
            #build left subtree
            tree.left = self.buildTree(preorder[1:root_index+1], inorder[:root_index])
            #build right subtree
            tree.right = self.buildTree(preorder[root_index+1:], inorder[root_index+1:])
        return tree

        