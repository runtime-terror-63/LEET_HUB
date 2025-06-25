class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.length();
        int i=0, j=0;
        vector<vector<int>>ds;
        while(i<n){
            while(j<n && s[i]==s[j])j++;

            if(j-i>=3) ds.push_back({i, j-1});
            i = j;
        }
        return ds;
    }
};