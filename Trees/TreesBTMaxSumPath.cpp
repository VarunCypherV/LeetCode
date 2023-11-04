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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findMaxPathSum(root, maxSum);
        return maxSum;
    }
    //the apparsand in the func below means it references to the variable named maxSum
    int findMaxPathSum(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        int leftSum = max(0, findMaxPathSum(node->left, maxSum));
        int rightSum = max(0, findMaxPathSum(node->right, maxSum));
        int currentMax = node->val + leftSum + rightSum;
        maxSum = max(maxSum, currentMax);
        return node->val + max(leftSum, rightSum);
    }
};
