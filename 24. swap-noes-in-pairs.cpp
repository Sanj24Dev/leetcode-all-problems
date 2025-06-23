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
    ListNode* swapPairs(ListNode* head) {
        ListNode* left;
        ListNode* right;
        ListNode* prev;
        if (head == NULL || head->next == NULL) return head;
        ListNode* ret = head->next;
        left = head;
        right = head->next;
        prev = NULL;
        while(left && right) {
            // cout << left->val << " " << right->val << endl;
            if (prev)
                prev->next = right;
            left->next = right->next;
            right->next = left;

            prev = left;
            left = left->next;
            if (left)
                right = left->next;
            
        }

        return ret;
    }
};