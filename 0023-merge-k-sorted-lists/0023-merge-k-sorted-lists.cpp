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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val; //min heap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq; //min heap
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode * temp = dummy; //since temp = dummy so dummy's next will be the first node.
        
        while(!pq.empty()){
            ListNode* node = pq.top(); //top smallestt node
            pq.pop();
            if(node->next){ //if its next list exists push it
            pq.push(node->next);
            }
            temp->next = node; //add the node into the final list using temp ptr
            temp = temp->next; //move the temp ptr
        }
        return dummy->next; //ie, head of the temp list is dummy->next
    }
};