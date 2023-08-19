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
        while l1!=None or l2!=None or carry!=0:
            val1=l1.val if l1!=None else 0
            val2=l2.val if l2!=None else 0
            sum = val1 + val2 + carry
            digit = sum%10
            carry = sum//10
            pointer.next=ListNode(digit)
            pointer = pointer.next
            l1=l1.next if l1!=None else None
            l2=l2.next if l2!=None else None
        return temp.next
    
        