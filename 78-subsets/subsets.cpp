class Solution {
public:
    void fn(vector<vector<int>>&res, vector<int>&ds, vector<int>&arr, int i){
        if(i>=arr.size()){
            res.push_back(ds);
            return ;
        }
        ds.push_back(arr[i]);
        fn(res, ds, arr, i+1);
        ds.pop_back();
        fn(res, ds, arr, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        fn(res, ds, nums, 0);
        return res;
    }
};