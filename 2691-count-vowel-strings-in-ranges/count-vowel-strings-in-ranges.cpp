class Solution {
public:
   bool isVowel(char c){
  return c =='a' || c=='e'||c=='i'||c=='o'||c=='u';
}
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
  int cnt = 0;
  vector<int>prefix;
  for(auto& it : words){
    if(isVowel(it[0]) && isVowel(it[it.size()-1]))
    cnt++;

    prefix.push_back(cnt);
  }

  vector<int>ans;
  for(auto it : queries){
    int l = it[0];
    int r = it[1];

    if(l==0) ans.push_back(prefix[r]);
    else ans.push_back(prefix[r]-prefix[l-1]);
  }
  return ans;
}
};