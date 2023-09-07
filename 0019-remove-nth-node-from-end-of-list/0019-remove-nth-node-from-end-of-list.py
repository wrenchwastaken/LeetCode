# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        current = head
        while current:
            count += 1
            current = current.next
        check = count - n - 1
        count = 0
        current = head
        if check == -1:
            return head.next
        while current:
            if count == check:
                current.next = current.next.next
                break
            current = current.next
            count += 1
        return head