



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
