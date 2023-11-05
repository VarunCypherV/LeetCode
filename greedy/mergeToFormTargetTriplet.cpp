class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> maxTriplet = {0, 0, 0};
         // Initialize a triplet to keep track of the maximum values seen
    
        for (const vector<int>& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
            // Check if the current triplet is a valid candidate for the operation
                maxTriplet[0] = max(maxTriplet[0], triplet[0]);
                maxTriplet[1] = max(maxTriplet[1], triplet[1]);
                maxTriplet[2] = max(maxTriplet[2], triplet[2]);
            }
            //BASCIALLY KEEP ANDING UNTIL U REACH TARGET ELSE FAlse
            if (maxTriplet == target) {
                // If the maximum triplet becomes equal to the target, return true
                return true;
            }
        }
    
        return false;
    }
};