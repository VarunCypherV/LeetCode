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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;      //if both null then hehe they r same
        }
       if (!p || !q || p->val != q->val) {
            return false;           //if either one is null or their values dont match then not same yaar
        }
        return  isSameTree(p->left,q->left) && isSameTree(p->right,q->right) ; 
        //both the sub tree of a root shud return true for the whole trees to be same trees
    }
        
};
