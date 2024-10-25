class Solution {
public:
int findAns(string& s){
  unordered_set<char>str{'a','e','i','o','u','A','E','I','O','U'};
  int cnt = 0;
  for(auto st : s){
    if(str.find(st) != str.end()) cnt++;
  }
  return cnt;
}
    bool halvesAreAlike(string s) {
        int len = s.length();
        int mid = len/2;
        string first_half = s.substr(0, mid);
        string second_half = s.substr(mid);
        return findAns(first_half)==findAns(second_half);
    }
};