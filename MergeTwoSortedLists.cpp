class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head;
        ListNode* current;
        if (list1->val < list2->val) {
            head = list1;
            current = list1;
            list1 = list1->next;
        } else {
            head = list2;
            current = list2;
            list2 = list2->next;
        }
        //choosing head so its the minimum we can choose there it self
        //now for reminder
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
                //add list1 element to the result ll current and go on
            } else {
                //else add list2 element
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        return head;
    }
};
