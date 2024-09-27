class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>mpp;
        int maxi = INT_MIN;
        int windowStart = 0;
        for(int windowEnd = 0; windowEnd<n; windowEnd++){
            mpp[fruits[windowEnd]]++;

            if(mpp.size()>2){
                mpp[fruits[windowStart]]--;
                if(mpp[fruits[windowStart]]==0) 
                mpp.erase(fruits[windowStart]);

                windowStart++;
            }
            maxi = max(maxi, windowEnd-windowStart+1);
        }
        return maxi;
    }
};