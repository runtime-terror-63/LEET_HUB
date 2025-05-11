class Solution {
public:
    int minDeletion(string s, int k) {
  map<char, int>mpp;
  for(auto it : s)mpp[it]++;

  if(mpp.size()==k) return 0;
  vector<int>cnt;
  for(auto it : mpp) cnt.push_back(it.second);
  sort(cnt.begin(), cnt.end());
  int result = 0;
  int last = mpp.size()-k;
  for(int i=0; i<last; i++){
    result+= cnt[i];
  }
  return result;
    }
};