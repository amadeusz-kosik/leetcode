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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // current: will point to the element to delete
        ListNode *current = head;

        // previous: will point to the element before the current
        ListNode *previous = head;

        // pilot: will go to the end of the list to determine last element
        ListNode *pilot = head;

        // pilot goes first, with (n) offset to pilot
        for(int i = 0; i < (n - 1); ++ i) {
            pilot = pilot->next;
        }

        // Run to the end of the list.
        while(pilot->next != nullptr) {
            previous = current;
            current = current->next;
            pilot = pilot->next;
        }

        if(previous != current) {
            // Delete element from the middle of the list.
            previous->next = current->next;
            delete current;
            return head;
        } else {
            // Edge case: delete head of the list.
            current = head->next;
            delete head;
            return current;
        }
    }
};
