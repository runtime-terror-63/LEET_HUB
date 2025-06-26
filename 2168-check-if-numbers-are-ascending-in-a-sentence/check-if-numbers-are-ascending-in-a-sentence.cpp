class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int>ds;
        string word = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]!= ' ') word+=s[i];
            else{
            if(all_of(word.begin(), word.end(), ::isdigit))
            ds.push_back(stoi(word));
            word = "";
            }
        }
        if(all_of(word.begin(), word.end(), ::isdigit)) ds.push_back(stoi(word));

        int prev = 0;
        for(auto it : ds) {
            if(it>prev){
            prev = it;
            }else return false;
        }
        return true;
    }
};