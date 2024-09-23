class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
        int n = nums.size();
        vector<int>arr(n, -1);
        for(int i = 0; i<n; i++){
            for(int j = 1; j,n; j++){
                int k = (i+j)%n;

                if(nums[k]>nums[i]){
                    arr[i] = nums[k];
                    break;
                }
            }
        }
        return arr; */

        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i = 2*n-1; i>=0; i--){

            //we pop elemnt smaller than current
            while(!st.empty() && (nums[i%n]>=st.top())) st.pop();

            //is stack is emty means no greater wlwmnt there
            //if not then we make answer at the top index
            if(!st.empty() && (i<n)) ans[i] = st.top();
            st.push(nums[i%n]);
        }

return ans;

    }
};