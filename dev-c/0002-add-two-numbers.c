/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* add_two_numbers(struct ListNode *l1, struct ListNode *l2, int carry) {
    if(l1 == NULL && l2 == NULL && carry == 0) {
        return NULL;
    }
    
    bool hasNext = false;
    int newVal = carry;

    struct ListNode *nl1 = NULL;
    struct ListNode *nl2 = NULL;

    if(l1 != NULL) {
        nl1 = l1 -> next;
        newVal += l1 -> val;
    }

    if(l2 != NULL) {
        nl2 = l2 -> next;
        newVal += l2 -> val;
    }

    hasNext = (nl1 != NULL || nl2 != NULL) || newVal >= 10;
    struct ListNode *newNode = (struct ListNode *) calloc(1, sizeof(struct ListNode)); 
    newNode -> val = newVal % 10;

    if(hasNext) {
        newNode -> next = add_two_numbers(nl1, nl2, newVal / 10);
    }

    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return add_two_numbers(l1, l2, 0);
}
