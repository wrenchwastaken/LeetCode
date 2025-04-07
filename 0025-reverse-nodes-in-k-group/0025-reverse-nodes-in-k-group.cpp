/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp!=nullptr && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* kth = getKthNode(temp,k);
            if(kth == nullptr){
                if(prev != nullptr){
                    prev->next = temp;
                }
                break;
            }
            ListNode* nextNode = kth->next;
            kth->next = nullptr;
            reverseLL(temp);
            if(temp == head){
                head = kth;
            }
            else{
                prev->next = kth;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};