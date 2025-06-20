class Solution {
public:
    int characterReplacement(string s, int k) {
  int n = s.length();
  int l=0, r=0, maxFreq = 0, toReplace = 0, result = 0;
  unordered_map<char, int>mpp;

  while(r<n){
    mpp[s[r]]++;
    maxFreq = max(maxFreq, mpp[s[r]]);

    int windowSize = r-l+1;
    toReplace = windowSize-maxFreq;

    if(toReplace>k){
      mpp[s[l]]--;
      l++;
    }

    result = max(result, r-l+1);
    r++;
  }
  return result;
    }
};