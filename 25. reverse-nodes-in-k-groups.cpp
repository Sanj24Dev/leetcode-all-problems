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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* groupStart = head;
        ListNode* groupEnd = head;
        for (int i = 1; i < k; i++) {
            if (groupEnd)
                groupEnd = groupEnd->next;
            else
                return head;
        }
        ListNode* ret = groupEnd;
        ListNode* left = groupStart;
        ListNode* right = groupStart->next;
        ListNode* prevGrpStart = nullptr;
        ListNode* temp;
        
        while (groupEnd) {
            if (prevGrpStart) {
                prevGrpStart->next = groupEnd;
            }
            prevGrpStart = groupStart;
            groupStart = groupEnd->next;
            
            while (left != groupEnd && right) {
                // cout << left->val << right->val << endl;
                temp = right->next;
                right->next = left;
                left = right;
                right = temp;
            }
            if (right == nullptr) {
                prevGrpStart->next = nullptr;
                break;
            }
            // groupStart = left;
            groupEnd = groupStart;
            for (int i = 1; i < k; i++) {
                if (groupEnd)
                    groupEnd = groupEnd->next;
            }
            
            if (groupEnd) {
                // cout << groupStart->val << groupEnd->val << endl;
                left = groupStart;
                right = left->next;
            }
            else {
                prevGrpStart->next = groupStart;
            }
            
        }
        
        // print_list(ret);
        return ret;
    }

    void print_list(ListNode* r) {
        ListNode* d = r;
        while (d) {
            cout << d->val << " ";
            d = d->next;
        }
        cout << endl;
    }
};