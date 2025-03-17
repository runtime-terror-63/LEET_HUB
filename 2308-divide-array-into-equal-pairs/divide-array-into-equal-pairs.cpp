class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int>mpp;
        for(auto it : nums) mpp[it]++;
        int cnt = 0;
        for(auto it : mpp){
            if(it.second%2==0) cnt++;
            else return false;
        }

        return cnt==mpp.size();
    }
};