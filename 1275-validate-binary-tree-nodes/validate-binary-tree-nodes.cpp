class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector<int> prn(n, 0);
    int rc = 0, root = -1;
    for (int i = 0; i < n; ++i) {
        if (leftChild[i] != -1) prn[leftChild[i]]++;
        if (rightChild[i] != -1) prn[rightChild[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (prn[i] == 0) {
            rc++;
            root = i;
        }
    }
    if (rc != 1) return false;
    vector<bool> vis(n, false);
    int visitedNodes = 0;
    function<bool(int)> dfs = [&](int node) {
        if (node == -1) return true;
        if (vis[node]) return false;
        
        vis[node] = true;
        visitedNodes++;

        return dfs(leftChild[node]) && dfs(rightChild[node]);
    };
        if (!dfs(root)) return false;
       return visitedNodes == n;
    }
};