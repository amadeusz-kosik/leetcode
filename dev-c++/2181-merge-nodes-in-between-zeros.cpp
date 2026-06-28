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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *read = head->next;
        ListNode *write = head;

        while(read != nullptr) {
            if(read->val == 0) {
                if(read->next == nullptr) {
                    write->next = nullptr;
                    return head;
                } else {
                    write->next = read;
                    write = read;
                    read = read->next;
                }
            } else {
                ListNode *tmp = read->next;
                write->val += read->val;
                delete read;
                read = tmp;
            }
        }

        return head;
    }
};
