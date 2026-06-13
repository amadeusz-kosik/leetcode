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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) { return head; }

        ListNode* tail = head;
        ListNode* next = head->next;

        tail->next = nullptr;
        
        while(next != nullptr) {
            ListNode *stash = next->next;
            next->next = tail;
            tail = next;
            next = stash;
        }

        return tail;
    }
};
