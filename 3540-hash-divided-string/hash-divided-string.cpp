class Solution {
public:
    string stringHash(string s, int k) {
  unordered_map<char, int>mpp;
  for(auto i = 'a'; i<='z'; i++)
   mpp[i] = i-'a';

  string res = "";
  int n = s.length();
  int numstring = n/k;

  for(int i = 0; i<numstring; i++){
    string substring = s.substr(i*k, k);
    int sum = 0;
    for(auto c : substring)
       sum += mpp[c];

     int hashMap = sum % 26;
     res += char( 'a' + hashMap);
  } 
  return res;

        
    }
};