class Solution {
public:
   int solve1(vector<int> arr)
{
    int ind = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for (int i = 1; i < ind; i++)
    {
        int pick = arr[i];
        if (ind > 1)
        pick += prev2;
        int non_pick = prev;

        int curri = max(pick, non_pick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>arr1(nums.begin()+1, nums.end());
        vector<int>arr2(nums.begin(), nums.end()-1);

        long long int ans1 = solve1(arr1);
        long long int ans2 = solve1(arr2);

        return max(ans1, ans2);
    }
};