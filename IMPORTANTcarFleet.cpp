class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        if (size == 0) {
            return 0;
        }
        vector<pair<int, int>> cars;
        for (int i = 0; i < size; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> stack;
        stack.push((static_cast<double>(target) - static_cast<double>(cars[size - 1].first)) / static_cast<double>(cars[size - 1].second));
        //handlin flaot with static_cast (typecast) //sort in desc then go from first in loop or other way around doesnt matter
        for (int i = size - 2; i >= 0; i--) {
            double time = (static_cast<double>(target) - static_cast<double>(cars[i].first)) / static_cast<double>(cars[i].second);
            if (time > stack.top()) {
                stack.push(time);
            }
        }
        return stack.size();
    }
};
