class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
  string a = s.substr(0, 1);
  int cnt = 0;
  for(auto it : words){
    if(it.substr(0, 1)==a) {
      if(s.substr(0, it.length()) == it  && it.length()<=s.length()) cnt++;
    }
  }
  return cnt;
    }
};