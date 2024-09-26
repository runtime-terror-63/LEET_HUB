class Solution {
public:
    int countGoodSubstrings(string s) {
        int windowStart = 0;
        int k = 3;
        int ans = 0;
        for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            if (windowEnd - windowStart + 1 == k) {
               
                if(s[windowStart] != s[windowStart + 1] && 
                    s[windowStart] != s[windowStart + 2] && 
                    s[windowStart + 1] != s[windowStart + 2])
                    ans++;

                windowStart++;  
            }
        }
        return ans; 
    }
};