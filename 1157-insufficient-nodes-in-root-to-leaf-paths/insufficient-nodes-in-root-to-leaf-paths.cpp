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
    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {
        if(root==NULL) return nullptr;

        sum += root->val;
        if(!root->left && !root->right){
            if(sum<limit) return nullptr;
            return root;
        }

        root->left = sufficientSubset(root->left, limit, sum);
        root->right =  sufficientSubset(root->right, limit, sum);

        if(root->left==NULL && root->right==NULL) return nullptr;
        return root;
    }
};