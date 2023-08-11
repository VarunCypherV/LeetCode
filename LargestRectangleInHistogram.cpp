class Solution {
public:
    int max(int a , int b){
        int r = (a>b)?a:b ;
        return r;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            int height = heights[stack.top()];
            stack.pop();
            int width = stack.empty() ? heights.size() : heights.size() - stack.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};
