/* Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         if (!head || !head->next) return head;
        vector <ListNode*> res;
        ListNode* tmp;
        // push to result vector
        ListNode* node = head;
        while(node)
        {
            res.emplace_back(node);
            node = node->next;
        }
        // swap 0 & 1 index value, 2 & 3, 4 & 5 ...... n-1 & n
        for(int i=0; i<res.size()-1; i=i+2){
            tmp = res[i];
            res[i] = res[i+1];
            res[i+1] = tmp;
        }
        // link lists to the next index node
        for(int i=0; i< res.size()-1; i++){
            res[i] -> next = res[i+1];
        }
        // set null for last node
        res[res.size()-1] -> next = nullptr;
        
        // return first node of the list
        return res[0];
    }
    
};
