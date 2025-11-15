/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *last1 = head;
    struct ListNode *last  = head;

    if(head == NULL)
        return head;

    while(last -> next != NULL)
        last = last -> next;

    if(last == head)
        return head;
    
    while(last1 -> next != last) 
        last1 = last1 -> next;

    last1 -> next = NULL;
    last -> next = reverseList(head);
    
    return last;
}