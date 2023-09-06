# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        previous = None
        current = head
        while current:
            if current.val == val and previous:
                previous.next = current.next
                current = current.next
                continue
            elif current.val == val and not previous:
                head = head.next
                current = current.next
                continue
            previous = current
            current = current.next
        return head