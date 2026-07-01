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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> buffer;
        traversal(root, buffer);
        return buffer;
    }

private:
    void traversal(TreeNode* root, vector<int> &buffer) {
        if(root != nullptr) {
            traversal(root->left, buffer);
            buffer.push_back(root->val);
            traversal(root->right, buffer);
        }
    }
};