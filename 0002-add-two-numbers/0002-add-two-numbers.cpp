class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        int carry = 0;
        ListNode* curr = dummy;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1)
                sum += l1->val;
            if (l2)
                sum += l2->val;
            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            curr->next = newnode;
            curr = curr->next;
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};