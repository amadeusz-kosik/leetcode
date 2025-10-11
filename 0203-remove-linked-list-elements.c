/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL) {
        return NULL;
    } else if(head -> val == val) {
        return removeElements(head -> next, val);
    } else {
        head -> next = removeElements(head -> next, val);
        return head;
    }
}