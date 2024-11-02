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
    void fn(TreeNode* root, vector<string>&ans, string temp){
        if(!root) return ;
        temp += to_string(root->val);
        if(!root->left && !root->right)
        ans.push_back(temp);
        else  {
            temp += "->";
            fn(root->left, ans, temp);
            fn(root->right, ans, temp);
        }

        temp.pop_back();

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp = "";
        fn(root, ans, temp);
        return ans;
    }
};