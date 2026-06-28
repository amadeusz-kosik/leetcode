/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *current = head;

        while(current != nullptr) {
            if(current->child != nullptr) {
                Node *child = current->child;
                Node *child_end = child;

                if(current->next != nullptr) {
                    while(child_end->next != nullptr) { child_end = child_end->next; }

                    child_end->next = current->next;
                    current->next->prev = child_end;
                }                 
                
                current->next = child;
                child->prev = current;

                current->child = nullptr;
            }

            current = current->next;
        }

        return head;
    }
};
