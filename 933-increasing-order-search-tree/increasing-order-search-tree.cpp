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
   void inorder(TreeNode* root, vector<int>&ans){
    if(root==NULL) return ;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
   }

   TreeNode* solve(vector<int>&v, int index){
    if(index>=v.size()) return NULL;
    TreeNode* root = new TreeNode(v[index]);
    root->right = solve(v, index+1);
    return root;
   }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        sort(v.begin(), v.end());
        return solve(v, 0);
    }
};