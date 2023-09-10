# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        new = None
        current = head
        while current:
            nextNode = current.next
            current.next = new
            new = current
            current = nextNode
        return new
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        temp1 = self.reverseList(slow)
        temp2 = head
        while temp1 and temp2:
            if temp1.val != temp2.val:
                return False
            temp1 = temp1.next
            temp2 = temp2.next
        return True