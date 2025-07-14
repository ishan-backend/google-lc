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
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        
        //bit manipulation
        while(head)
        {
            // abhi tk ke results ko ek baar left shift since head is valid
            ret = ret * 2;
            
            // or operator to set the current bit
            ret |= head -> val;
            
            head = head -> next;
        }
        return ret;
    }
};