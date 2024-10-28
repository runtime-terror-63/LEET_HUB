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
   int decimaltoBinary(string& str){
 int n = str.length();
 int decimal = 0, power = 0;
 for(int i = n-1; i>=0;i--){
  if(str[i]=='1') decimal += (1<<power);
  power++;
 }
 return decimal;
}
void solve(TreeNode *root, string&res, int&ans)
{

  if (root == nullptr)
    return;
  res.push_back((root->val+'0'));
  if (root->left == nullptr && root->right == nullptr)
     ans  +=  decimaltoBinary(res);
  solve(root->left, res, ans);
  solve(root->right, res, ans);

  res.pop_back();
}

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        string str;
        solve(root, str, ans);
        return ans;
    }
};