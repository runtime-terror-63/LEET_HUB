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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> zigzag;
  queue<TreeNode *> que;
  bool leftoright = true;

  if (root == NULL)
    return zigzag;

  que.push(root);

  while (!que.empty())
  {
    int size = que.size();
    vector<int> ans(size); 

    for (int i = 0; i < size; i++)
    {
      root = que.front();
      que.pop();

     
      int index = leftoright ? i : size - 1 - i;

     ans[index] = root->val;

      if (root->left != NULL)
        que.push(root->left);
      if (root->right != NULL)
        que.push(root->right);
    }


    leftoright = !leftoright;

    zigzag.push_back(ans);
  }

  return zigzag;
    }
};