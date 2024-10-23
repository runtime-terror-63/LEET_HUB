class Solution {
public:
    int findMin(vector<int>& arr) {
          int n = arr.size();
            int mini = 1e9;
            for (int i = 0; i < n; i++)
            {
                mini = min(mini, arr[i]);
            }
            return mini;
    }
};