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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> lvl;  

            //size of elemnts in the que
            for (int i = 0; i < size; i++) {
                //just get the elemnts ans pop out
                TreeNode* node = que.front();
                que.pop();
                //if there left and also right then say me
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                //push them in vector
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};
