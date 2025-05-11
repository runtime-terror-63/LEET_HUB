class Solution {
public:
    int maxFreqSum(string s) {
          map<char, int> mpp;
  int maxi = 0, sum = 0;

  for (auto it : s) {
    if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') 
      mpp[it]++;
  }

  for (auto it : mpp) {
    maxi = max(maxi, it.second);
  }

  sum += maxi;

  maxi = 0;
  mpp.clear();

  for (auto it : s) {
    if (it != 'a' && it != 'e' && it != 'i' && it != 'o' && it != 'u') 
      mpp[it]++;
  }

  for (auto it : mpp) {
    maxi = max(maxi, it.second);
  }

  sum += maxi;
  return sum;
    }
};