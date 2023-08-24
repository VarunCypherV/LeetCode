//best two pointer

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int area = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    area += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    area += rightMax - height[right];
                }
                right--;
            }
        }
        return area;
    }
};



//lLogic works but TLE

class Solution {
public:
    int min(int a,int b){
        return (a<b)?a:b;
    }
    int trap(vector<int>& height) {
        
        int area=0;
        int left=0;
        int right=2;
        int flag=0;
        while(right<=height.size()-1){
           if(right==height.size()-1){flag=1;}
           if(height[left]<height[right]){
               right--;
               while(right>left){
                   area+=height[left]-height[right];
                   right--;
               }
           }
           if(flag==1){
               break;
           }
            right++;
        }
        return area;
    }
};
