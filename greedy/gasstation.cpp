class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0;
        int currentGas = 0;
        int startStation = 0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            totalGas += diff;
            currentGas += diff;
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        return totalGas >= 0 ? startStation : -1;
    }
};
