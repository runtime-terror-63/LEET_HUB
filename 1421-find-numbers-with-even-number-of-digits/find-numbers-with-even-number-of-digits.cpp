class Solution {
public:
   bool check(int num){
    int cnt = 0;
    while(num>0){
        cnt++;
        num = num/10;
    }
    return cnt%2==0;
   }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto it : nums){
            if(check(it)) cnt++;
        }
        return cnt;
    }
};