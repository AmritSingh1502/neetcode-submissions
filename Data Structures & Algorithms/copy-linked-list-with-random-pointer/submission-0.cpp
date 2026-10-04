/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        // phase1 create clones and interleave them with the original list

        Node* curr = head;

        while(curr != nullptr){
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // phase 2 : wire up the random pointers for the clones

        curr = head;

        while(curr != nullptr){
            if(curr->random != nullptr){
                // the clone random is the original's random's clone
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // phase 3 : separate then interwoven list back into two distinct lists
        curr = head;

        Node* cloneHead  = head->next;

        while(curr != nullptr){
            Node* clone = curr->next;
            curr->next = clone->next; // restore the original list
            if(clone->next != nullptr){
                clone->next = clone->next->next; // connect the clone list
            }
            curr = curr->next;
        }

        return cloneHead;
    }
};
