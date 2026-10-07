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
private:
    ListNode* getKthNode(ListNode* curr , int k){
        while(curr != nullptr && k > 0){
            curr = curr->next;
            k--;
        }

        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while(true){
            // find the kth node
            ListNode* kth = getKthNode(groupPrev, k);

            if(!kth){
                break;
            }

            ListNode* groupNext = kth->next;

            // step 2  reverse the current k group

            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;


            while(curr != groupNext){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev= curr;
                curr= tmp;
            }

            // step 3 : re attach the reversed group back to main list
            ListNode* tmp =groupPrev->next;
            groupPrev->next = kth;

            groupPrev = tmp;
        }

        return dummy.next;
    }
};
