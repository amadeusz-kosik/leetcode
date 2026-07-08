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
    int sumNumbers(TreeNode* root) {
        return sum_numbers(root, 0);
    }

    int sum_numbers(const TreeNode* root, const int prefix) const {
        if(root == nullptr) { return 0; } 

        if(root->left != nullptr || root->right != nullptr) { 
            return sum_numbers(root->left,  prefix * 10 + root->val) + sum_numbers(root->right, prefix * 10 + root->val); 
        } else {
            return prefix * 10 + root->val;
        }
        
    }
};