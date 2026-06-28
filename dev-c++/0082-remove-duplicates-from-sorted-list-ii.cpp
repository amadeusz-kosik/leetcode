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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) { return head; }
        
        ListNode *r_head = new ListNode(-1);
        ListNode *r_last = r_head;

        while(head != nullptr) {
            if(head->next == nullptr) {
                // Last element: add to results
                r_last->next = head;
                r_last = head;

                head = head->next;
            } else if(head->val != head->next->val) {
                // Distinct element: add to results
                r_last->next = head;
                r_last = head;   

                head = head->next;             
            } else {
                int val = head->val;

                while(head->val == val) {
                    ListNode *tmp = head;
                    head = head->next;
                    delete tmp;

                    if(head == nullptr) { break; }
                }
            }
        }

        r_last->next = nullptr;
        r_last = r_head->next;
        
        delete r_head;
        return r_last;
    }
};
