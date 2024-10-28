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
    void getAns(TreeNode* root, int x, int y, TreeNode* parent, int depth, pair<TreeNode*, int>&xray, pair<TreeNode*, int>&yray){
    if(!root) return ;
    if(root->val==x) xray = {parent, depth};
    else if(root->val==y) yray = {parent, depth};
    if(xray.first && yray.first) return ;
    getAns(root->left, x, y, root, depth+1, xray, yray);
    getAns(root->right, x, y, root, depth+1, xray, yray);

    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<TreeNode*, int> xray = {nullptr, -1};
            pair<TreeNode*, int> yray = {nullptr, -1};
            getAns(root, x, y, nullptr, -1, xray, yray);

            return xray.second==yray.second && xray.first != yray.first;
    }
};