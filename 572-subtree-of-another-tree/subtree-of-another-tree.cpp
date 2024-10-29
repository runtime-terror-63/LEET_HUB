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
    void fn(TreeNode* root, string& s){
  queue<TreeNode*>q;
  q.push(root);
  s += root->val + '0';
  while(!q.empty()){
    auto val = q.front();
    q.pop();
    if(val->left){
      s+= val->left->val +'0';
      q.push(val->left);
    }else if(!val->left) s+='#';
    if(val->right){
      s+= val->right->val +'0';
      q.push(val->right);
    }else if(!val->right) s+='#';
  }
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  string s;
  fn(subRoot, s);
  cout<<s<<" ";
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    
    auto val = q.front();q.pop();
    if(val->val==subRoot->val){
       string k;
       fn(val, k);
       cout<<k<<" ";
       bool flag = true;
       if(k.size()==s.size()){
        for(int i = 0; i<k.size(); i++){
            if(k[i]!=s[i]) flag = false;
        }
        if(flag==true) return true;
       }
    }

    if(val->left) q.push(val->left);
    if(val->right) q.push(val->right);
  }
  return false;
}
};