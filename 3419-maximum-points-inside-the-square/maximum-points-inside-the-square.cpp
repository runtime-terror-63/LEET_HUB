class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char, int>mpp;
        int sec_min = INT_MAX, cnt = 0;

        for(size_t i = 0; i<points.size(); i++){
            int len = max(abs(points[i][0]), abs(points[i][1]));
            char c = s[i];

            if(mpp.find(c) == mpp.end()){
                mpp[c] = len;
            }else if(len < mpp[c]) {
                sec_min = min(sec_min, mpp[c]);
                mpp[c] = len;
            }else sec_min = min(sec_min, len);
        }



        for(auto& it : mpp){
            if(it.second < sec_min)  cnt++;
        }

        return cnt;
    }
};