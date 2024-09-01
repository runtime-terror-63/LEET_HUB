class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n1!=n2) return false;
        unordered_map<char, char>mp1;
        unordered_map<char, char>mp2;
        for(int i = 0; i<n1; i++){
           
          //  if(s[i]==t[i])continue;
            if(mp1.find(s[i]) != mp1.end()) {
                if(mp1[s[i]] != t[i]) return false;
            }

            if(mp2.find(t[i]) != mp2.end()) {
                if(mp2[t[i]] != s[i]) return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};