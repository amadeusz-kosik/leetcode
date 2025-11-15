/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(n == 1 && head -> next == NULL) {
        // Remove only element
        return NULL;
    } else if(n == 1) {
        // Remove last element
        
        struct ListNode *current = head;

        while(current -> next -> next != NULL)
            current = current -> next;

        current -> next = NULL;
        return head;
    } else {
        // There is something after the removed

        struct ListNode *current = head;
        struct ListNode *lag_n = head;

        for(int i = 0; i < n; ++ i)
            current = current -> next;

        if(current == NULL) {
            // Remove first element of the list
            return head -> next;
        } else {
            while(current -> next != NULL) {
                current = current -> next;
                lag_n = lag_n -> next;
            }

            lag_n -> next = lag_n -> next -> next;
            return head;
        }
    }  
}