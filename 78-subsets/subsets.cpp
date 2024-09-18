class Solution {
public: 
    void solve(int ind, int n, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds){
        if(ind==n){
            ans.push_back(ds);
            return ;
        }

        ds.push_back(nums[ind]);
        solve(ind+1, n, nums, ans, ds);
        ds.pop_back();
        solve(ind+1, n, nums, ans, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0, n, nums, ans, ds);
        return ans;
    }
};