class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        long long maxEle =-1;
        for(auto it : milestones){
            sum += it;
        }

        maxEle = *max_element(milestones.begin(), milestones.end());
        
        long long othermileSt = sum - maxEle;
        if(othermileSt<maxEle) return 2 * othermileSt+1;
        return sum;
    }
};