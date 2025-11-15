/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head != NULL) {
        while(head -> next != NULL && head -> next -> val == head -> val) {
            head -> next = head -> next -> next;
        }
        head -> next = deleteDuplicates(head -> next);
    }
    
    return head;
}