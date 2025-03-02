class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        unordered_map<int, int>mpp;
       

        for(int i=0; i<=nums.size()-k; i++){
             set<int>ds;
            for(int j=i; j<k+i; j++){
                ds.insert(nums[j]);
            }

            for(auto it : ds) mpp[it]++;
        }


        int maxi = -1;

        for(auto it : mpp){

            cout<<it.first<<" "<<it.second<<endl;;
            if(it.second==1){
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};