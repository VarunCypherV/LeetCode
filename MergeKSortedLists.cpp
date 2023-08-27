//I AM TOO GOOD
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* result = new ListNode();
        ListNode* head = result;
        vector<int> res;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current) {
                res.push_back(current->val);
                current = current->next;
            }
        }
        sort(res.begin(),res.end());

        for (int i = 0; i < res.size(); i++) {
           ListNode* dummy = new ListNode(res[i]);
           result->next=dummy;
           result=result->next;
        }

        return head->next;
    }
};

//my concept but terrible runtime lol
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode();
        ListNode* head = result;
        int iters = 0;
        //mama mia get me the count of items i need to iter in total
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current) {
                iters++;
                current = current->next;
            }
        }
        //find the mind among all and add it
        for (int i = 0; i < iters; i++) {
            int minVal = INT_MAX;
            int minIdx = -1;
            
            for (int j = 0; j < lists.size(); j++) {
                if (lists[j]) {
                    if (lists[j]->val < minVal) {
                        minVal = lists[j]->val;
                        minIdx = j;
                    }
                }
            }
            
            if (minIdx != -1) {
                result->next = new ListNode(minVal);
                result = result->next;
                lists[minIdx] = lists[minIdx]->next; //move the head of that particular item in list so that no dupe occurs
            }
        }

        return head->next;
    }
};
