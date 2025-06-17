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

void inorder(TreeNode* root, vector<int>&ans) {
  if(!root) return ;
  inorder(root->left, ans);
  ans.push_back(root->val);
  inorder(root->right, ans);
}
    vector<int> findMode(TreeNode* root) {
          vector<int>ans;
  inorder(root, ans);

  unordered_map<int, int>mpp;
  int maxi = -1;
  for(auto it : ans){
    mpp[it]++;
    maxi = max(maxi, mpp[it]);
  }

  vector<int>ds;
  for(auto it : mpp){
    if(it.second==maxi) ds.push_back(it.first);
  }
  return ds;
    }
};