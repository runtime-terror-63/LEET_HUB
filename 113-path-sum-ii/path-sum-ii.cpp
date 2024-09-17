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
   void traverse(TreeNode* root, int targetSum, int currSum, vector<vector<int>>&ans, vector<int>&curr){
    if(root==NULL) return ;
    curr.push_back(root->val);
    if(!root->left && !root->right){
        if(targetSum==(currSum+root->val)) ans.push_back(curr);
    }
    traverse(root->left, targetSum, currSum+root->val, ans, curr);
    traverse(root->right, targetSum, currSum+root->val, ans, curr);
    curr.pop_back();
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        int currSum = 0;
        traverse(root, targetSum, currSum, ans, curr);
        return ans;
    }
};