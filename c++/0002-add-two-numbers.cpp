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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if(l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        
        bool hasNext = false;
        int newVal = carry;

        ListNode *nl1 = nullptr;
        ListNode *nl2 = nullptr;

        if(l1 != nullptr) {
            nl1 = l1 -> next;
            newVal += l1 -> val;
        }

        if(l2 != nullptr) {
            nl2 = l2 -> next;
            newVal += l2 -> val;
        }

        hasNext = (nl1 != nullptr || nl2 != nullptr) || newVal >= 10;
        ListNode *newNode = new ListNode(newVal % 10);

        if(hasNext) {
            newNode -> next = addTwoNumbers(nl1, nl2, newVal / 10);
        }

        return newNode;
    }
};