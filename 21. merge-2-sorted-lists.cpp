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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = NULL;
        if (list1 != NULL || list2 != NULL) {
            ListNode* head = NULL;
            int l1 = list1!=NULL?list1->val:INT_MAX;
            int l2 = list2!=NULL?list2->val:INT_MAX;
            if (l1 < l2) {
                head = list1;
                list1 = list1->next;
            }
            else {
                head = list2;
                list2 = list2->next;
            }
            ret = head;
            while (list1 && list2) {
                if (list1->val < list2->val) {
                    head->next = list1;
                    list1 = list1->next;
                }
                else {
                    head->next = list2;
                    list2 = list2->next;
                }
                head = head->next;
            }
            while (list1) {
                head->next = list1;
                list1 = list1->next;
                head = head->next;
            }
            while (list2) {
                head->next = list2;
                list2 = list2->next;
                head = head->next;
            }
        }
        return ret;
    }
};