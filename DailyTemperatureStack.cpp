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








//O(n^2) for loop TLE basic soln
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        //given array such as [73 74 72 75]
        // find no of days towards right where temp>current temp

        for(int i = 0 ; i<temperatures.size();i++){
            int count=0;
            int flag=0;
            for(int j=i+1;j<temperatures.size();j++){
                if(temperatures[i]<temperatures[j]){
                    count++;
                    flag=1;
                    break;
                }     
                else{
                    count++;
                }                     
            }
            if(flag==0){
                count=0; // No future day
            }
            answer.push_back(count);
        }
        return answer;
    }
};
