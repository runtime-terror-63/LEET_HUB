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

TreeNode *target;
void solve(unordered_map<TreeNode *, TreeNode *> &mpp, TreeNode *root, int start)
{
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *curr = q.front();
    if (curr->val == start)
      target = curr;
    q.pop();
    if (curr->left)
    {
      mpp[curr->left] = curr;
      q.push(curr->left);
    }

    if (curr->right)
    {
      mpp[curr->right] = curr;
      q.push(curr->right);
    }
  }
}
    int amountOfTime(TreeNode* root, int start) {
          unordered_map<TreeNode *, TreeNode *> mpp;
  solve(mpp, root, start);

  unordered_map<TreeNode *, bool> visisted;
  queue<TreeNode *> q;
  q.push(target);
  int maxi = 0;
  visisted[target] = true;
  while (!q.empty())
  {
    int fl = 0;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->left && !visisted[curr->left])
      {
        visisted[curr->left] = true;
        q.push(curr->left);
        fl = 1;
      }

      if (curr->right && !visisted[curr->right])
      {
        visisted[curr->right] = true;
        q.push(curr->right);
        fl = 1;
      }

      if (mpp[curr] && !visisted[mpp[curr]])
      {
        visisted[mpp[curr]] = true;
        q.push(mpp[curr]);
        fl = 1;
      }
    }
    if (fl)
      maxi++;
  }
  return maxi;
    }
};