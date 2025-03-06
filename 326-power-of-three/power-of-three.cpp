class Solution {
public:
    bool isPowerOfThree(int n) {
       while(n>0){
        if(n%3==0) n/=3;
        else break;
       }
       if(n==1) return true;
       return false;
      // return n==1;
    }
};