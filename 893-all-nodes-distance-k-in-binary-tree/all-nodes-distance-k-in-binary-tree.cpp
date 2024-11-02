/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_lock) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left) {
                parent_lock[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_lock[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parent_lock;
        markParent(root, parent_lock);
        
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;

        int dist = 0;
        while (!q.empty()) {
            if (dist++ == k) break;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if (parent_lock.count(curr) && !visited[parent_lock[curr]]) {
                    q.push(parent_lock[curr]);
                    visited[parent_lock[curr]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};
