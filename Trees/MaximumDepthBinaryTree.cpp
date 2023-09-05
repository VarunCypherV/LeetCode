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
};
