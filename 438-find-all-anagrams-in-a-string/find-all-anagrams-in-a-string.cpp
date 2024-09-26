class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int>mpp;
        for(auto it : p) mpp[it]++;
        vector<int>ans;
        int k = p.size();
        int cnt = mpp.size();
        int windowStart = 0;
        for(auto windowEnd = 0; windowEnd<s.length(); windowEnd++){
            if(mpp.find(s[windowEnd]) != mpp.end()){
                mpp[s[windowEnd]]--;
                if(mpp[s[windowEnd]]==0) cnt--;
            }

            if(windowEnd-windowStart+1==k) {
                if(cnt==0) ans.push_back(windowStart);

                //slide the window
                if(mpp.find(s[windowStart]) != mpp.end()){
                    mpp[s[windowStart]]++;
                    if( mpp[s[windowStart]]==1) cnt++;
                }

                 windowStart++;
            }

           
        }
        return ans;
    }
};