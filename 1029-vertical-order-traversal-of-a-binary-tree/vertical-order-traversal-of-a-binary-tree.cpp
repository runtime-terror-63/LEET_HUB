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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Base case for empty tree
        vector<vector<int>> res;
        if(!root) return res;
 map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode *, pair<int, int>>> q;
  q.push({root, {0, 0}});

  while (!q.empty())
  {
    auto node = q.front();
    q.pop();

    TreeNode *temp = node.first;
    int x = node.second.first;
    int y = node.second.second;

    nodes[x][y].insert(temp->val);
    if (temp->left)
      q.push({temp->left, {x - 1, y + 1}});
    if (temp->right)
      q.push({temp->right, {x + 1, y + 1}});
  }

  

  for (auto it : nodes)
  {
    vector<int> col;
    for (auto val : it.second)
      col.insert(col.end(), val.second.begin(), val.second.end());
    res.push_back(col);
  }
  return res;
    }
};
