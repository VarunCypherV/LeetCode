

//correct but tle 
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
    bool hasCycle(ListNode *head) {
        if(!head){return false;}
        if(!head->next){return false;}

        ListNode* curr2 = head->next;
        while(curr2 && curr2->next){
            ListNode* curr1 = curr2->next;
            while(curr1->next && curr1){
                if(curr1->val==curr2->val){
                    return true;
                };
                curr1=curr1->next;
            }
        }
        return false;
    }
};
