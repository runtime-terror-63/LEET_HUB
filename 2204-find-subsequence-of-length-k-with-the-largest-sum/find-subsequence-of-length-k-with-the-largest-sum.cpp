class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        int i=0;
        while(k>0){
            ans.push_back(nums[i]);
            i++;
            k--;
        }

        for(int ind=i; ind<n; ind++){
            int mini = min_element(ans.begin(), ans.end())-ans.begin();
            if(ans[mini]<nums[ind]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[ind]);
            }
        }
        return ans;
    }
};