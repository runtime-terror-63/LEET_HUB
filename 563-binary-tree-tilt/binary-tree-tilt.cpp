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
    int fn(TreeNode *root, int &tilt)
{
  if (root == NULL)
    return 0;
  int lh = fn(root->left, tilt);
  int rh = fn(root->right, tilt);
  tilt += abs(lh - rh);
  return root->val + lh + rh;
}
int findTilt(TreeNode *root)
{
  int tilt = 0;
  fn(root, tilt);
  return tilt;
}
};