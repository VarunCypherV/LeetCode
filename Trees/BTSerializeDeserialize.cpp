//NEW CONCEPT : STRING STREAM!!!!!!!!!!!!!!!!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        }
        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);
        return to_string(root->val) + "," + leftStr + "," + rightStr;
    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data); //NEW STUFF
        string node;
        while (getline(ss, node, ',')) {
            nodes.push(node);
        }
        return deserializeHelper(nodes);
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        string valStr = nodes.front();
        nodes.pop();
        if (valStr == "null") {
            return nullptr;
        }

        int val = stoi(valStr);
        TreeNode* root = new TreeNode(val);
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);

        return root;
    }
};
