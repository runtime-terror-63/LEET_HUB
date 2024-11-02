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
    int fn(TreeNode* root){
        if(!root) nullptr;
        if(!root->left && !root->right) return root->val;
        return fn(root->left) + fn(root->right);
    }
    bool checkTree(TreeNode* root) {
        int curr = root->val;

        return fn(root) ==curr;
    }
};