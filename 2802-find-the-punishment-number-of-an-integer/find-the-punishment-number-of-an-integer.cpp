class Solution {
public:
    bool is_possilble(string& s, int ind, int currSum, int target){
  if(ind==s.size()) return currSum == target;
  int num = 0;
  for(int i=ind; i<s.size(); i++){
    num = num*10+( s[i]-'0');

    if(currSum+num>target)  break;
    if(is_possilble(s, i+1, currSum+num, target)) return true;
  }
  return false;
}
int punishmentNumber(int n) {
  vector<int>ds;
  for(int i=1; i<=n; i++){
    int squre = i*i;
    string s = to_string(squre);

    if(is_possilble(s, 0,0,i)) ds.push_back(stoi(s));
  }
  int totalSum = 0;
  for(auto it : ds) totalSum+= it;
  return totalSum;
}

/*
n=10 
1 = 1*1 = 1 |  sum 1
2 = 2*2 = 4 |  sum 4 --> not applicable
9 = 9*9 = 81|  sum 8+1 = 9
10 = 10*10 = 100 | sum 10 + 0 = 10
1 + 81 + 100 = 182


n=37
1 = 1*1=1 | sum 1
9 = 9*9=81| sum 8+1 = 9
10 = 10*10=100 | sum 10+0 = 10
36 = 36*36=1296 | sum 1+29+6 = 36
1 + 81 + 100 + 1296 = 1478
*/
};