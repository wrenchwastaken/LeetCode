# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return None
        fast,slow,previous = head,head,head
        while fast and fast.next:
            previous = slow
            fast = fast.next.next
            slow = slow.next
        previous.next = slow.next
        return head