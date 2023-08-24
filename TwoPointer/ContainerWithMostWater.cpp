
class Solution {
public:
    int min(int a,int b){
        return (a<=b)?a:b;
    }
    int max(int a,int b){
        return (a<=b)?b:a;
    }

    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            long area = (long)width * minHeight;

            maxArea = max(maxArea, area);
             //min ht has to inc for area to inc so we inc that side
            (height[left] < height[right]) ? left++ : right-- ;
        }
        return maxArea;
    }
};

