class Solution {
public:
    int solve(vector<int> arr, int ind){
       int prev = arr[0];
       int prev2 = 0;
       for(int i = 1; i<ind; i++){
        int pick = arr[i];
        if(ind>1) pick += prev2;
        int non_pick =  prev;

        int curri = max(pick, non_pick);
        prev2 = prev;
        prev = curri;
       }
       return prev;
    }
    int rob(vector<int>& nums) {
        int ind = nums.size();
        return solve( nums, ind);
    }
};