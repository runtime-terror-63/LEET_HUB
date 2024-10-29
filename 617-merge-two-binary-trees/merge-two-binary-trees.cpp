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
    
TreeNode* mergeTrees(TreeNode* root1, TreeNode*root2){
  if(!root1 && !root2) return nullptr;
  if(!root1) return  root2;
  if(!root2) return root1;
  queue<pair<TreeNode*, TreeNode*>>q;
  q.push({root1, root2});
  while(!q.empty()){
    auto x = q.front(); q.pop();
    x.first->val += x.second->val;

    if(x.first->left && x.second->left) 
      q.push({x.first->left, x.second->left});
    else if(x.second->left) x.first->left = x.second->left;  

    if(x.first->right && x.second->right)
      q.push({x.first->right, x.second->right});
    else if(x.second->right) x.first->right = x.second->right;
  }
  return root1;
}
};