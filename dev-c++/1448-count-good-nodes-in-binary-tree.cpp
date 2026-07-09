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
    int goodNodes(TreeNode* root) {
        good_nodes(root, root->val);
        return (int) good_nodes_count;
    }

    void good_nodes(TreeNode *root, int local_max) {
        if(root == nullptr) { return; }

        if(root->val >= local_max) { 
            good_nodes_count += 1; 
            local_max = root->val;
        }
        
        good_nodes(root->left,  local_max);
        good_nodes(root->right, local_max);
    }
private:
    size_t good_nodes_count = 0;    
};