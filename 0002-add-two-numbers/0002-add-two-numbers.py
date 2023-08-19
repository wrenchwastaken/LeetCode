# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode()
        pointer = temp
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1Val = l1.val if l1 else 0
            l2Val = l2.val if l2 else 0
            sum = l1Val + l2Val + carry
            carry = sum//10
            newNode = ListNode(sum%10)
            pointer.next = newNode
            pointer = newNode
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return temp.next