class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
  int n = bills.size();
  map<int, int>mpp;
  if(bills[0]!=5) return false;
  mpp[5]++;
  for(int i=1; i<n; i++){
    if(bills[i]==5){
      mpp[5]++;
    }else if(bills[i]==10){
      if(mpp[5]>0){
        mpp[5]--;
        mpp[10]++;
      }else return false;
    }else if(bills[i]==20){
      if(mpp[5]>0 && mpp[10]>0){
        mpp[5]--;
        mpp[10]--;
        mpp[20]++;
      }else if(mpp[5]>=3){
        mpp[5] -= 3;
      }
      else return false;
    }
  }
  return true;
    }
};