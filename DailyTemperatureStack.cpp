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

//intuituion : local maximum 
// the while index not empty and temp check : it checks if incoming element is greater than or eq current top if yes pops existing top 
// then it measures distance of current element wrt the existing 
// pushes it self
// every iteration checks for local max then measures distance then pushes itself as it can be a local maximum for next element as well , its a stack of indexes of all local maximas
