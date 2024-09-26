class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int windowStart = 0;
        for(auto windowEnd = 0; windowEnd<s.length(); windowEnd++){
            if(windowEnd-windowStart+1<k) windowEnd++;
            if(windowEnd-windowStart+1==k){
                st.insert(s.substr(windowStart, k));
                windowStart++;
            }
            
        }
        if(st.size()==pow(2, k)) return true;
        return false;
    }
};