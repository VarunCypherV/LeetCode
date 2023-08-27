/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//The fast Slow approach
//  Initialize two pointers slow and fast to the head of the linked list.
// Start a loop where the fast pointer moves two steps and the slow pointer moves one step.
// If there is a cycle, the fast pointer will eventually catch up with the slow pointer.
// If the fast pointer or its next node becomes nullptr, there is no cycle in the linked list.
// Return true if the pointers meet (cycle detected), otherwise return false
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false; // No cycle if there are less than 2 nodes
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            if (slow == fast) {
                return true; // Cycle detected
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false; // No cycle found
    }
};


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
