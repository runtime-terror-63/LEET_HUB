class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int>mpp;
        for(auto it : nums) mpp[it]++;
        int j=0;
        for(auto it : mpp){
            if(it.second%2==0)j++;
            else return false;
        }
        return j==mpp.size();
    }
};