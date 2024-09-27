class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int windowStart = 0;
        int cnt = 0, maxi = 0;
        if(n==1) return 1;
        for(auto windowEnd =1; windowEnd<n; windowEnd++){
            if(s[windowEnd]==s[windowEnd-1]) cnt++;

            while(cnt>1){
                if(s[windowStart]==s[windowStart+1]) cnt--;
                windowStart++;
            }


            maxi = max(maxi, windowEnd-windowStart+1);
        }
        return maxi;
    }
};