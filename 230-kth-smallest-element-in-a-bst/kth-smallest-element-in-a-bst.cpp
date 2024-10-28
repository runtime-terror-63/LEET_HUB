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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> res;
            int size = q.size();
            for (auto i = 0; i < size; i++)
            {
            root = q.front();
            q.pop();
            res.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
            }
            ans.insert(ans.end(), res.begin(), res.end());
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};