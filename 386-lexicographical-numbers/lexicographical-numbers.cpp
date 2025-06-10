class Solution {
public:
    vector<int> lexicalOrder(int n) {
  vector<string>s;
  for(int i=1; i<=n; i++){
  string a = to_string(i);
    s.push_back(a);
  }
   sort(s.begin(), s.end());

  vector<int>ans;
  for(auto it : s) ans.push_back(stoi(it));
  return ans;
    }
};