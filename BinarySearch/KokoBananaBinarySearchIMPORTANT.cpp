class Solution {
public:
    int BinarySearch(vector<int>& piles, int target, int l, int r) {
        if (l > r) {
            return l; //return the value of l ie the prev iteration m value ie k as it falsified at beginning of this iteration so prev k is the crct value
        }
        int m = l + (r - l) / 2;
        long h = 0;
        for (long x : piles) {
            h += (x + m - 1) / m;
        
        }
        if (h <= target) {
            return BinarySearch(piles, target, l, m - 1); 
        } else {
            return BinarySearch(piles, target, m + 1, r);
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int left = 1;
        int right = maxPile;

        return BinarySearch(piles, h, left, right);
    }
};
