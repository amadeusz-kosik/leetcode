/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *head_a, struct ListNode *head_b) {
    struct ListNode* pointer_a = head_a;
    struct ListNode* pointer_b = head_b;

    while (pointer_a != pointer_b) {
        pointer_a = pointer_a != NULL ? pointer_a->next : head_b;
        pointer_b = pointer_b != NULL ? pointer_b->next : head_a;
    }

    return pointer_a;
}