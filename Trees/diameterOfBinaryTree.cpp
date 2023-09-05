//best soln same my idea 
class Solution {
public:
    int maxz=0; //global variable instead of passing into function

    int height(TreeNode* root){
        if(root == NULL){
             return 0;
        }
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        maxz= max(maxz, 1 + lHeight + rHeight); //1 + children ht instead of count ++ kek
        return 1 + max(lHeight , rHeight); // 1 + children ht instead of count++
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
             return 0;
        }
        height(root);
        return maxz-1;
    }
};



// below soln logic is correct but one test case alone failed
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDep(TreeNode* root , int count , int max){
        if(root==nullptr){
            max= (count>max)?count:max;
            return max;
        }
        count++;
        int ld=maxDep(root->left,count,max);
        int rd=maxDep(root->right,count,max);
        max=(ld>rd)?ld:rd;
        return max;
    }
    int maxDepth(TreeNode* root) {
        int max = INT_MIN;
        int count = 0;
        return maxDep(root,count , max);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max =INT_MIN;
        while(root){
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            int sum = left+ right;
            max=(sum>max)?sum:max;
            root=root->left;
        }
        while(root){
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            int sum = left+ right;
            max=(sum>max)?sum:max;
            root=root->right;
        }
        return max;
    }
};
