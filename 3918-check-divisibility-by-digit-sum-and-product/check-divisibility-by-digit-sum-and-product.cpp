class Solution {
public:
    
int sum(int n){
  int sum = 0;
  while(n>0){
    int a = n%10;
    sum+=a;
    n/=10;
  }
  return sum;
}

int prd(int n){
  int prd = 1;
  while(n>0){
    int a = n%10;
    prd*=a;
    n/=10;
  }
  return prd;
}

bool checkDivisibility(int n) {
  int cal = sum(n) + prd(n);
  if(n%cal==0) return true;
  else return false; 
}
};