class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          unordered_map<char, int>mpp;
  int i=0, j = 0;
  int n = s.length();
  int maxWindow = 0;
  while(j<n){
    mpp[s[j]]++;
    if(j-i+1==mpp.size()){
      maxWindow = max(maxWindow, j-i+1);
      //j++;
    }else if(j-i+1>mpp.size()){
      while(j-i+1>mpp.size()){
        mpp[s[i]]--;
        if(mpp[s[i]]==0)mpp.erase(s[i]);
        i++;
      }
    }
    j++;
  }
  return maxWindow;
    }
};