class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string>st(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto it : message){
            if(st.find(it) != st.end()) cnt++;
        }

        if(cnt>1) return true;
        return false;
    }
};