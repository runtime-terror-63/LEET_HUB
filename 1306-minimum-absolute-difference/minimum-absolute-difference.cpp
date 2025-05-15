class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        map<vector<int>, int>cnt;
        int mi = INT_MAX;

        for(int i=1; i<arr.size(); i++){
            mi = min(mi, arr[i]-arr[i-1]);
        }

        map<int, int>mpp;
        for(auto it : arr) mpp[it]++;
        for(auto it : arr){
            vector<int>v1;
            if(mpp[it+mi]){
                v1.push_back(it);
                v1.push_back(it+mi);
                sort(v1.begin(), v1.end());
                if(!cnt[v1]) ans.push_back(v1);
            }
        }
        return ans;
    }
};