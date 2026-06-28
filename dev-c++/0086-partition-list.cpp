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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) { return nullptr; }

        ListNode *lesser_head  = nullptr;
        ListNode *greater_head = nullptr;
        
        ListNode *lesser_ptr  = nullptr;
        ListNode *greater_ptr = nullptr;

        ListNode *current_ptr = head;

        while(current_ptr != nullptr) {
            if(current_ptr->val < x) {
                if(lesser_head == nullptr) {
                    lesser_head = current_ptr;
                } else {
                    lesser_ptr->next = current_ptr;
                }          

                lesser_ptr = current_ptr;      
            } else {
                if(greater_head == nullptr) {
                    greater_head = current_ptr;
                } else {
                    greater_ptr->next = current_ptr;
                }

                greater_ptr = current_ptr;
            }

            ListNode *next_ptr = current_ptr->next;
            current_ptr->next = nullptr;
            current_ptr = next_ptr;
        }

        if(lesser_head  == nullptr) { return greater_head; }
        if(greater_head == nullptr) { return lesser_head;  }

        lesser_ptr->next = greater_head;
        return lesser_head;
    }
};
