class Solution {
public:
   string pushDominoes(string d){
  int n = d.size();
  vector<int>forces(n, 0);
  int res = 0;
  for(int i=0; i<n; i++){
    if(d[i]=='R') res = n;
    else if(d[i]=='L') res = 0;
    else res = max(res-1, 0);

    forces[i]+=res;
  }


  res = 0;
  for(int i=n-1; i>=0; i--){
    if(d[i]=='L') res = n;
    else if(d[i]=='R') res = 0;
    else res = max(res-1, 0);

    forces[i] -= res;
  }


  string ans;
  for(auto f : forces){
    if(f>0) ans += 'R';
    else if (f<0) ans += 'L';
    else ans += '.';
  }
  return ans;
}
};