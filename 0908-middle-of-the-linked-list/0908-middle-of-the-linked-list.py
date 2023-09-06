# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        new = ListNode
        new.next = head
        slow = new
        fast = new
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
        return slow.next