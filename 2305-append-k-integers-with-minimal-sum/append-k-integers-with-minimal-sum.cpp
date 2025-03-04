class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long newVal = 1, sum = 0;
        for(auto it : nums){

            while(it>newVal && k>0){
                sum+=newVal;
                newVal++;
                k--;
            }

            if(it==newVal)newVal++;
        }

        cout<<newVal<<endl;

        while(k>0){
            sum += newVal;
            newVal++;
            k--;
        }
        return sum;
    }
};