class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        vector<string>words;
        stringstream ss(s);
        unordered_map<char, string>mp1;
        unordered_map<string, char>mp2;
        while(ss>>word) words.push_back(word);

        if(pattern.length() != words.size()) return false;
        for(int i = 0; i<pattern.length(); i++){
            char c = pattern[i];
            string w = words[i];

            if(mp1.find(c) != mp1.end()){
                if(mp1[c] != w) return false;
            }

            if(mp2.find(w) != mp2.end()){
                if(mp2[w] != c) return false;
            }

            mp1[c] = w;
            mp2[w] = c;

        }
        return true;
    }
};