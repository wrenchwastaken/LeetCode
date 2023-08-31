# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        self.curr = root

    def next(self) -> int:
        while self.curr:
            if not self.curr.left:
                val = self.curr.val
                self.curr = self.curr.right
                return val
            else:
                pred = self.curr.left
                while pred.right and pred.right != self.curr:
                    pred = pred.right
                if pred.right == self.curr:
                    pred.right = None
                    val = self.curr.val
                    self.curr = self.curr.right
                    return val
                else:
                    pred.right = self.curr
                    self.curr = self.curr.left
        

    def hasNext(self) -> bool:
        return self.curr is not None
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()