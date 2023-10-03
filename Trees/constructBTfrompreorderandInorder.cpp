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
    //     To construct a binary tree from its preorder and inorder traversals, you can follow these steps recursively:

    // Find the root of the tree from the preorder traversal.
    // Locate the root's position in the inorder traversal.
    // Recursively construct the left subtree using the left portion of the inorder traversal.
    // Recursively construct the right subtree using the right portion of the inorder traversal.
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  // Initialize variables for the start and end of preorder and inorder arrays
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  // Create a map to store the indices of elements in the inorder traversal
  map<int, int> mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }
  // Call the helper function to construct the binary tree
  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}


TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
  // Base case: If there are no elements to process, return NULL
  if (preStart > preEnd || inStart > inEnd) {
    return NULL;
  }

  // Create a new TreeNode with the current root value from preorder
  TreeNode* root = new TreeNode(preorder[preStart]);

  // Find the index of the root value in the inorder traversal
  int elem = mp[root->val];

  // Calculate the number of elements in the left subtree
  int nElem = elem - inStart;

  // Recursively construct the left subtree with appropriate index ranges
  root->left = constructTree(preorder, preStart + 1, preStart + nElem, inorder, inStart, elem - 1, mp);

  // Recursively construct the right subtree with appropriate index ranges
  root->right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, elem + 1, inEnd, mp);

  // Return the root of the current subtree
  return root;
}


};
