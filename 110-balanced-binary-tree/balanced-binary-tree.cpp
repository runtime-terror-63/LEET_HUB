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
/*
    int height(TreeNode* root)
    {
        //either root is null return null
        if(root==NULL) return NULL;
        //height of lh...
        int lh = height(root->left);
        //height of rh...
        int rh = height(root->right);
        //absolute value of l and rh.. is greter then 1 the return -1;
        if(abs(lh-rh)>1) return -1;
        //if lh is -1 the return -1..
        if(lh == -1) return -1;
        //id rh is -1 the return -1..
        if(rh == -1) return -1;
        //max of lh and rh ....
        return max(lh, rh)+1;

        return 1;

    }
    */

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)>1) return  -1;
        if(lh==-1) return -1;
        if(rh==-1) return -1;
        return max(lh, rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;

       
    }
};