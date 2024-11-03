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
    int cnt = 0;
int fn(TreeNode *root)
{

 queue<TreeNode *> q;
        q.push(root);
        cnt = 1;
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                cnt++;
            }
            if (curr->right) {
                q.push(curr->right);
                cnt++;
            }
        }
        return cnt;
}
int countNodes(TreeNode *root)
{
    if(root==NULL) return 0;
  fn(root);
  return cnt;
}
};