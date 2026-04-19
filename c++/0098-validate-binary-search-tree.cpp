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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* node, const long min_value, const long max_value) {
        if(node == nullptr) { return true; }
        if(node -> val <= min_value || node -> val >= max_value) { return false;}

        if(! isValidBST(node -> left,  min_value, node -> val)) { return false; }
        if(! isValidBST(node -> right, node -> val, max_value)) { return false; }

        return true;
    }
};
