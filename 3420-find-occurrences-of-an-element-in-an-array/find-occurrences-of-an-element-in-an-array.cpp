class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        unordered_map<int, vector<int>>mpp;
        for(int i=0; i<n; i++)
            mpp[nums[i]].push_back(i);
        vector<int>ans;
        for(auto q : queries){
            if(mpp[x].size()>=q) 
            ans.push_back(mpp[x][q-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};