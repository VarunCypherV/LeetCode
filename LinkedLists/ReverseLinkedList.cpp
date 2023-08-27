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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; //helps in updating next part of second (next) node with the current node
        while (head != NULL) {
            ListNode* next = head->next; //helps in ref to second (next) node when updating first node's next to null so that we can reverse
            head->next = prev; // connecting current head to prev head (reversing the arrow)
            // making current head to prev and moving head to next node so that u can connect the arrow when next is head in next iteration
            prev = head;  
            head = next;  
        }
        head = prev; // pointing to last node
        return head;
    }
};


RECURSION IMPLEMENATION
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
    ListNode* recursion(ListNode* head ,ListNode* prev){
        if(head==NULL){
            head=prev;
            return head;
        }
        ListNode* next = head->next;
            head->next = prev; 
            prev = head;  
            head = next;  
        return   recursion(head,prev);
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        return recursion(head , prev);
        
        
    }
};
