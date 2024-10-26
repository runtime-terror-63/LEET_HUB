class Solution {
public:
    bool func(string &s1, string &s2, int k) {
        set<string> st;
        for (auto i = 0; i <=s1.length()-k; i++) {
            st.insert(s1.substr(i, k));
        }
        
        for (auto i = 0; i <=s2.length()-k; i++) {
            if (st.find(s2.substr(i, k)) != st.end())
                return true;
        }
        return false;
    }

    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        string str1 = "";
        string str2 = "";
        for (int i = 0; i < n1; i++)
            str1 += nums1[i] + '0';
        for (int j = 0; j < n2; j++)
            str2 += nums2[j] + '0';

        int low = 0, high = min(n1, n2);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (func(str1, str2, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
