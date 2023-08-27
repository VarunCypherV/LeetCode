class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int count = 0;
        // length da
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        current = head;
        if (count - n == 0) { //first node
            head = head->next;
            delete current;
            return head;
        }
        //middle and end : one before that
        for (int i = 1; i < count - n; i++) {
            current = current->next;
        }
        //deletee
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        
        return head;
    }
};
