"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        # Create a new node for each original node and connect them
        current = head
        while current:
            new_node = Node(current.val, None)
            new_node.next = current.next
            current.next = new_node
            current = new_node.next
        
        # Set random pointers for the new nodes
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next
        
        # Separate the original and new linked lists
        current = head
        new_head = current.next
        while current:
            new_node = current.next
            current.next = new_node.next
            if new_node.next:
                new_node.next = new_node.next.next
            current = current.next
        
        return new_head
        