class Solution {
public:
    string findValidPair(string s) {
  unordered_map<char, int>mpp;
  for(auto it : s) mpp[it]++;
  string ans = "";
  for(int i=0; i<s.length()-1; i++){
    char first = s[i], second = s[i+1];
    if(first != second && (first-'0')==mpp[first] && (second-'0')==mpp[second]){
     return string() + first + second;
    }
  }
  return "";
    }
};