//CONCEPT OF REVERSE THE GIVEN VECTOR AND SUE STACK
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> indexStack;     
        for (int i = n - 1; i >= 0; i--) {
            while (!indexStack.empty() && temperatures[i] >= temperatures[indexStack.top()]) {
                indexStack.pop();
            }
            if (!indexStack.empty()) {
                answer[i] = indexStack.top() - i;
            }
            indexStack.push(i);
        }
        return answer;
    }
};
