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
    void putCopyinBetween(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copyNode = new Node(temp->val);
            Node* nextNode = temp->next;
            copyNode->next = nextNode;
            temp->next = copyNode;
            temp = nextNode;
        }
    }
    void connectRandomPointer(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copyNode = temp->next;
            if(temp->random != nullptr){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* connectNextandExtract(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp != nullptr){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        putCopyinBetween(head);
        connectRandomPointer(head);
        return connectNextandExtract(head);
    }
};