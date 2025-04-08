class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j = 0;
  int n = s.length();
  int maxFreq = 0, ans = 0;
  unordered_map<char, int>mpp;
  while(j<n){
    mpp[s[j]]++;
    maxFreq = max(maxFreq, mpp[s[j]]);

    if(maxFreq+k>=j-i+1) { 
       ans = max(ans, j-i+1);
    }
    else if(maxFreq+k<j-i+1){
      while(maxFreq+k<j-i+1){
        mpp[s[i]]--;
        i++;
      }
      ans = max(ans, j-i+1);
    }
    j++;
  }
  return ans;
    }
};