class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
         if(s1==s2) return true;
 
 vector<int>diff;
 for(int i=0; i<s1.length(); i++){
  if(s1[i]!=s2[i])diff.push_back(i);
 }


 return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && 
 s1[diff[1]] == s2[diff[0]];
    }
};