class Solution {
public:
   void solve(int ind, vector<vector<int>>&ans, vector<int>&ds, vector<int>&candidates, int n, int target){
    if(ind==n){
        if(target==0) ans.push_back(ds);
        return ;
    }

    //pick
    if(candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        solve(ind, ans, ds, candidates, n,  target-candidates[ind]);
        ds.pop_back();
    }
    //not-pick
    solve(ind+1, ans, ds, candidates, n,  target);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0, ans, ds,candidates, n, target);
        return ans;
    }
};