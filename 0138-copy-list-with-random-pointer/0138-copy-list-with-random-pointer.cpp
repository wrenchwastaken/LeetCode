/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // inserted copy nodes in between the nodes;
        Node*temp = head;
        while(temp!=NULL){
            Node*newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        // join the random links;
        temp = head;
        while(temp!=NULL){
            Node*t2 = temp->next;
            if(temp->random == NULL)t2->random = NULL;
            else t2->random = temp->random->next;
            temp = temp->next->next;
        }
        //join the next links;;;
        temp = head;
        Node*dummy = new Node(-1);
        Node*res = dummy;

        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }   
        return dummy->next;
    }
};