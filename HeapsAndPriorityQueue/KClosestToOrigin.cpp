//SOMETHING NEW : LAMBDA FUNCTIONS AND make_heap


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Define a lambda function to compare two points by their distance to the origin
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return sqrt(a[0] * a[0] + a[1] * a[1]) > sqrt(b[0] * b[0] + b[1] * b[1]);
        };
        // Create a min-heap using the lambda function as the comparator
        make_heap(points.begin(), points.end(), cmp);

        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(points.front());
            pop_heap(points.begin(), points.end(), cmp);
            points.pop_back(); 
        }
        return result;
    }
};
