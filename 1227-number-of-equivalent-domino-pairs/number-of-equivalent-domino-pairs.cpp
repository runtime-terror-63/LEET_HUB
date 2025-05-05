class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int>mpp;
        int res = 0;
        for(auto it : dominoes){
            int a = it[0], b = it[1];

            int key = min(a, b) * 10 + max(a, b);
            res += mpp[key];
            mpp[key]++;
        }
        return res;
    }
};