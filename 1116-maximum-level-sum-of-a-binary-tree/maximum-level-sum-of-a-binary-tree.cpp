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
    int maxLevelSum(TreeNode* root) {
         queue<TreeNode*>q;
  q.push(root);
  int mini = INT_MIN;
  int curr_level = 1, max_level = 1;
  while(!q.empty()){
    int size = q.size();
    int sum = 0;
    for(int i=0; i<size; i++){
      TreeNode* curr = q.front();
      q.pop();
      sum += curr->val;
      if(curr->left) q.push(curr->left);
      if(curr->right) q.push(curr->right);
    }
    if(sum>mini){
        mini = sum;
        max_level = curr_level;
    }
    curr_level++;
    }
    return max_level;
    }
};