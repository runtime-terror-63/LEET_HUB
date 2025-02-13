class Solution {
public:
bool solve(vector<int>& nums, vector<vector<int>>& queries, int ind) {
    vector<int> curr(nums.size() + 1, 0);

    for (int i = 0; i <= ind; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];

        curr[l] += val;
        curr[r + 1] -= val;
    }

    //  prefix sum
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) curr[i] += curr[i - 1]; 
        if (curr[i] < nums[i]) return false;
    }
    return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    if (solve(nums, queries, -1)) return 0;

    int res = -1;
    int l = 0, r = queries.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (solve(nums, queries, mid)) {
            res = mid + 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
};