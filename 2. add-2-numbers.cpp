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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int d1, d2, carry=0;
        ListNode* prev = NULL;
        ListNode* ret = NULL;
        while (l1!=NULL || l2!=NULL) {
            d1 = l1!=NULL?l1->val:0;
            d2 = l2!=NULL?l2->val:0;
            ListNode* node = new ListNode((d1+d2+carry)%10);
            if (d1+d2+carry >= 10)
                carry = 1;
            else
                carry = 0;
            if (prev!=NULL) {
                prev->next = node;
            }
            else{
                ret = node;
            }
            prev = node;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry != 0)
        {
            ListNode* node = new ListNode((carry)%10);
            prev->next = node;
        }
        return ret;
    }
};