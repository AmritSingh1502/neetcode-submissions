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

    //custom comparator for the min heap
    struct compare {
        bool operator()(const ListNode* l , const ListNode* r){
            return l->val > r -> val ; // min heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      // prioritty queue(min heap) holding ListNode pointer
      priority_queue<ListNode*, vector<ListNode*>, compare> pq;

      // step 1 push the head of the each list in the min heap

      for(ListNode* listHead : lists) {
        if(listHead != nullptr){
            pq.push(listHead);
        }
      }

      ListNode dummy(0);
      ListNode* tail = &dummy;

      // step 2 extract minimum , appnd to result and push trhe next node from that list
      while(!pq.empty()){
        ListNode* smallest = pq.top();
        pq.pop();
        tail->next = smallest;
        tail = tail->next;

        // if the extracted noide has next node push to queue
        if(smallest -> next != nullptr){
            pq.push(smallest->next);
        }
      }

      return dummy.next;
    }
};
