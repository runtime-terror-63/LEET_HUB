class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>mpp;
        for(auto it : arr) mpp[it]++;
        int maxi = -1;
        for(auto it : mpp){
            if(it.first==it.second && maxi<it.first){
                maxi = it.first;
            } 
        }
        return maxi;
    }
};