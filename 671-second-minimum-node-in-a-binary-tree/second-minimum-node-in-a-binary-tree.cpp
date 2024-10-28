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
    int findSecondMinimumValue(TreeNode *root)
    {
    // bfs
    queue<TreeNode *> q;
    set<int> st;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        st.insert(root->val);
        if (root->left)
        q.push(root->left);
        if (root->right)
        q.push(root->right);
    }
    if (st.size() < 2)
        return -1;
    auto i = st.begin();
    i++;
    return *i;
    }
};