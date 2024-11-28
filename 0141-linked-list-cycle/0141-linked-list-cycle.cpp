/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        unordered_map<ListNode*,int> mpp;
        while(temp!=nullptr){
            if(mpp.find(temp)!=mpp.end()){
                return true;
            }
            mpp[temp]++;
            temp = temp->next;
        }
        return false;
    }
};