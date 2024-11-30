class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1!=nullptr && t2!=nullptr){
            if(t1->val <= t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1){
            temp->next = t1;
        }
        if(t2){
            temp->next = t2;
        }
        return dummy->next;
    }
};