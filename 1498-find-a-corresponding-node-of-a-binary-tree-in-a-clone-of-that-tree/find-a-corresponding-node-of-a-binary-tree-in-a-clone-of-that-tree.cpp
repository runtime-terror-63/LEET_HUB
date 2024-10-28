/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int min = -1;
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
           TreeNode* root = q.front();
            q.pop();
            if(root->val == target->val) return root;

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        return nullptr;
    }
};