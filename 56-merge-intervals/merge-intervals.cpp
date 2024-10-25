class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int temp = intervals[0][1];
        for(int i=1; i<n; i++){
            if(temp>=intervals[i][0]){
                temp = max(temp, intervals[i][1]);
                ans.back()[1] = temp;
            }else {
                ans.push_back(intervals[i]);
                temp = intervals[i][1];
            }
        }
        return ans;
    }
};