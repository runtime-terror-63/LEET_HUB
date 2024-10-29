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
    vector<int>getAns(TreeNode* root, vector<int>&ans){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto x = q.front(); q.pop();
            ans.push_back(x->val);
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        getAns(root, ans);
        sort(ans.begin(), ans.end());
        int i = 0, j = ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k) return true;
            else if(ans[i]+ans[j]>k) j--;
            else i++;
        }
        return false;
    }
};