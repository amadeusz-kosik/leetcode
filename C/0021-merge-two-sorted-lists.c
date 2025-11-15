/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *result;
    struct ListNode *last;

    if(list1 == NULL) {
        return list2;
    }  
    if(list2 == NULL) {
        return list1;
    }

    if(list1 -> val <= list2 -> val) {
        result = list1;
        list1 = list1 -> next;
    } else {
        result = list2;
        list2 = list2 -> next;
    }

    last = result;

    while(list1 != NULL && list2 != NULL) {
        if(list1 -> val <= list2 -> val) {
            last -> next = list1;
            list1 = list1 -> next;
        } else {
            last -> next = list2;
            list2 = list2 -> next;
        }
        last = last -> next;
    }

    if(list1 != NULL) {
        last -> next = list1;
    }

    if(list2 != NULL) {
        last -> next = list2;
    }

    return result;
}