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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *pilot = head;
        ListNode *previous = nullptr;
        ListNode *current = head;

        if(head->next == nullptr) {
            // Corner case: single element in the list.
            return nullptr;
        }

        while(true) {
            if(pilot->next != nullptr) { pilot = pilot->next; } else { break; }

            previous = current;
            current = current -> next;

            if(pilot->next != nullptr) { pilot = pilot->next; } else { break; }
        }

        if(previous == nullptr) {
            current = current->next;
            delete head;
            return current;
        } else {
            previous->next = current->next;
            delete current;
            return head;
        }
    }
};