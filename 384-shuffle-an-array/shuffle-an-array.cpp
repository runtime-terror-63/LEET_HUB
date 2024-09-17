class Solution {
public:
vector<int>original, sw;
    Solution(vector<int>& nums) {
        original = nums;
        sw = nums;
         next_permutation(nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return original;
        
    }
    
    vector<int> shuffle() {
        int ran =  rand();
        ran = ran%original.size();
        swap(sw[0], sw[ran]);
        return sw;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */