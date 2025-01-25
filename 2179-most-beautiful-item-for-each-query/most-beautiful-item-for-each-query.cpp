class Solution {
public:
int bs(int money, vector<vector<int>>&items){
  int low = 0, high = items.size()-1;
  int ans = -1;
  while(low<=high){
    int mid = (low+high)/2;
    if(items[mid][0] <=money){
      ans = mid;
      low = mid+1;
    }else high = mid-1;
  }
  return ans;
}
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
sort(items.begin(), items.end());
  int n = items.size();
  int q = queries.size();
  vector<int>beauty(n);
  beauty[0] = items[0][1];
  for(int i=1; i<n; i++)
   beauty[i] = max(beauty[i-1], items[i][1]);
   vector<int>ans(q);
   for(int i=0; i<q; i++){
    int query_ans = bs(queries[i], items);
    ans[i] = (query_ans==-1) ? 0 : beauty[query_ans];
   }
   return ans;
    }
};