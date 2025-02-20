class Solution {
public:
   string res = "";
void solve(int n, string curr, unordered_set<string>&s){
  if(curr.size()==n){
    if(s.find(curr)==s.end()) res = curr;
    return;
  }

  if(!res.empty()) return;
  solve(n, curr+'0', s);
  solve(n, curr+'1', s);
}
string findDifferentBinaryString(vector<string>& nums) {
  unordered_set<string>s(nums.begin(), nums.end());
  solve(nums[0].size(), "", s);
  return res;
    }
};