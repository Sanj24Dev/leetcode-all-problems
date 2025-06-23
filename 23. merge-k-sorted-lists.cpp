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

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        for (ListNode* l: lists) {
            if (l) {
                minHeap.push(l);
            }
        }
        ListNode* ret = new ListNode(0);
        ListNode* head = ret;
        while (!minHeap.empty()) {
            ListNode* least = minHeap.top();
            minHeap.pop();
            
            head->next = least;
            head = head->next;

            if (least->next)
                minHeap.push(least->next);
        }
        return ret->next;
    }
};