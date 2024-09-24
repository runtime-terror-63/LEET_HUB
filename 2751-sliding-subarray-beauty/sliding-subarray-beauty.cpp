#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
   int findXthSmallestNegative(deque<int> &l, int x) {
      if (l.size() < x) return 0;

      vector<int> negNums(l.begin(), l.end());
      sort(negNums.begin(), negNums.end());

      return negNums[x - 1];
   } */

   vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
     map<int, int>mpp;
      vector<int> ans;
      int windowStart = 0;

      for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
         if (nums[windowEnd] < 0) {
           mpp[nums[windowEnd]]++;
         }

         if (windowEnd - windowStart + 1 == k) {
            int cnt = 0, x_smallest = 0;
            bool flag = false;
            
            //find the x-smallest negetive element
            for(auto it = mpp.begin(); it!= mpp.end(); it++){
                cnt+= it->second;

                //cnt is now the 2nd negetive elemnt cnt
                if(cnt>=x){
                    x_smallest = it->first;
                    flag = true;
                    break;
                }
            }

            if(flag) ans.push_back(x_smallest);
            else ans.push_back(0);

            mpp[nums[windowStart]]--;
            if(mpp[nums[windowStart]]==0)mpp.erase(nums[windowStart]);

            windowStart++;
         }
      }

      return ans;
   }
};
