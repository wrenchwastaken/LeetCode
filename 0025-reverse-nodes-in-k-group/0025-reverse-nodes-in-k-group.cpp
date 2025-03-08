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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newH = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newH;
    }

    ListNode* findK(ListNode* head, int k){
        k -= 1;
        ListNode* temp = head;
        while(temp != nullptr && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevN = nullptr;
        while(temp != nullptr){
            ListNode* kN = findK(temp,k);
            if(kN == nullptr){
                if(prevN){
                    prevN->next = temp;
                    break;
                }
            }
            ListNode* nextN = kN->next;
            kN->next = nullptr;
            reverseLL(temp);
            if(temp == head){
                head = kN;
            }
            else{
                prevN->next = kN;
            }
            prevN = temp;
            temp = nextN;
        }
        return head;
    }
};