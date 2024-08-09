# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        visit = set()
        tempA, tempB = headA, headB
        while tempA or tempB:
            if tempA:
                if tempA in visit:
                    return tempA
                visit.add(tempA)
                tempA = tempA.next
            if tempB:
                if tempB in visit:
                    return tempB
                visit.add(tempB)
                tempB = tempB.next
        return None
        