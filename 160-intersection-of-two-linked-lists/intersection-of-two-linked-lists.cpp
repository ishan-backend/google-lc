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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ca = headA;
        ListNode* cb = headB;
        while(ca != cb) {
            if(ca == nullptr) {
                ca = headB;
            } else {
                ca = ca->next;
            }

            if(cb == nullptr) {
                cb = headA;
            } else {
                cb = cb->next;
            }
        }

        return ca;
    }
};