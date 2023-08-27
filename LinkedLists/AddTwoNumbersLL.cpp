// Best way
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return result->next;
    }
};

//Concept correct but exceeding long size for 3 test cases LOL
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* headl1 = l1;
        ListNode* headl2 = l2;
        ListNode* result = new ListNode();
        ListNode* temp = result;
        long long countl1 = 0, countl2 = 0, suml1 = 0, suml2 = 0, sum = 0;
        
        while (headl1 != NULL) {
            countl1++;
            suml1 += headl1->val * (pow(10, countl1 - 1));
            headl1 = headl1->next;
        }
        
        while (headl2 != NULL) {
            countl2++;
            suml2 += headl2->val * (pow(10, countl2 - 1));
            headl2 = headl2->next;
        }
        
        sum = suml1 + suml2;
        long long digit = sum % 10;
        sum = sum / 10;
        result->val = digit;
        result->next = NULL;
        temp = result;
        while (sum >= 1) {
            ListNode* newNode = new ListNode();
            temp->next = newNode;
            temp = temp->next;
            
            temp->val = sum % 10;
            temp->next = NULL;
            
            sum = sum / 10;
        }
        
        return result;
    }
};
