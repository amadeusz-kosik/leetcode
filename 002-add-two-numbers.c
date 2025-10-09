/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) 
        return l2;

    if(l2 == NULL)
        return l1;

    int result = 0;
    int carry  = 0;

    struct ListNode *result_l = l1;
    struct ListNode *last_l = l1;

    while(true) {
        // End of both lists
        if(l1 == NULL && l2 == NULL) {
            if(carry > 0) {
                last_l -> next = (struct ListNode *) malloc(sizeof(struct ListNode));
                last_l -> next -> val = carry;
                last_l -> next -> next = NULL;
                break;
            } 
            
            break;
        }
        // Only left list has ended
        else if(l1 == NULL) {
            if(carry > 0) {
                last_l -> next = (struct ListNode *) malloc(sizeof(struct ListNode));
                last_l -> next -> val = carry;
                last_l -> next -> next = NULL;
                
                carry = 0;
                l1 = last_l -> next;
            } 
            else {
                last_l -> next = l2;
                break;
            }
        }
        // Only right list has ended
        else if(l2 == NULL) {
            if(carry > 0) {
                l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
                l2 -> val = carry;
                l2 -> next = NULL;

                carry = 0;
                continue;
            } 
            else {
                break;
            }
        }
        else {
            result = (l1 -> val + l2 -> val + carry) % 10;
            carry = (l1 -> val + l2 -> val + carry) / 10;

            l1 -> val = result;
            last_l = l1;
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
    }
    
    return result_l;
}