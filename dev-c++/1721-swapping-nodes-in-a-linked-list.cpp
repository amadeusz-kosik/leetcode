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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fromHead = head;
        ListNode *fromTail = head;

        for(int i = 1; i < k; ++ i) { 
            fromHead = fromHead->next; 
        }

        ListNode *fromTailPilot = fromHead->next;

        while(fromTailPilot != nullptr) { 
            fromTailPilot = fromTailPilot->next;
            fromTail = fromTail->next; 
        }

        if(fromTail != fromHead) { 
            swap(fromHead->val, fromTail->val);
        }

        return head;
    }
};
