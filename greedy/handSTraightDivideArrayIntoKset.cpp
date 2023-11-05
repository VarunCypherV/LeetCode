class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
       if (hand.size() % groupSize != 0) {
            return false;
        }
        
        unordered_map<int,int> map;

        sort(hand.begin(), hand.end());
        for (int num : hand) {
            map[num]++;
        }
        
        for (int num : hand) {
            if (map[num] > 0) {
                for (int i = num + 1; i < num + groupSize; i++) {
                    if (map[i] == 0) {
                        return false;
                    }
                    map[i]--;
                }
                map[num]--;
            }
        }
        
        return true;

    }
};

