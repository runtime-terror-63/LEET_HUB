class Solution {
public:
    bool isPrime(int n){
  if(n==0 || n==1) return false;

  for(int i=2; i<=n/2; i++){
    if(n%i==0) return false;
  }
  return true;
}
    bool checkPrimeFrequency(vector<int>&nums){
    map<int, int>mpp;
    for(auto it : nums) mpp[it]++;
    for(auto it : mpp){
        if(isPrime(it.second)) return true;
    }
    return false;
    }
};