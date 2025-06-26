class Solution {
public:
    string sortSentence(string s) {
        map<int, string>mpp;
        vector<string>ds;
        string word = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
            word += s[i];
            }
            else{
            int ind = word.back()-'0';
            word.pop_back();
            ds.push_back(word);
            mpp[ind] = word;
            word = "";
            }
        }
        int a = stoi(word.substr(word.size()-1, 1));
        word.pop_back();
        ds.push_back(word);
        mpp[a] = word;

        
        // for(auto it : ds) cout<<it<<" ";
        // cout<<endl;

        //for(auto it : mpp) cout<<it.first<<" "<<it.second<<endl;
        // cout<<word<<endl;

        string ans = "";
        for(auto it : mpp) ans += it.second+" ";
        ans.pop_back();
        return ans;
    }
};