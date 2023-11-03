class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int count = 1; //cuz atleast 1 int lol
        int i = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; //end times
        });
        int end = intervals[0][1];
        while (i < intervals.size()) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
            i++;
        }
        return intervals.size() - count;
    }
};
