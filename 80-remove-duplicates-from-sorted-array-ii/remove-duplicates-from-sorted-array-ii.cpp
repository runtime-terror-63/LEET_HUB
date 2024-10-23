class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        unordered_map<int, int> mpp;
        int k = 0;
        for (auto it : arr)
        {
            mpp[it]++;
            if (mpp[it] <= 2)
            {
            arr[k] = it;
            k++;
            }
        }
        return k;
    }
};