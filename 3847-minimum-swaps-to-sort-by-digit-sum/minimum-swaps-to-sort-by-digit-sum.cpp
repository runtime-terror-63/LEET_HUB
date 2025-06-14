class Solution {
public:
static int isVal(int i){
  int sum = 0;
  while(i>0){
    int dx = i%10;
    sum += dx;
    i/=10;
  }
  return sum;
}

static bool  computeSort(pair<int, int>a, pair<int, int>b){
  int sumA = isVal(a.first);
  int sumB = isVal(b.first);
  if(sumA==sumB) return a.first<b.first;
  return sumA<sumB;
}

int minSwaps(vector<int>& nums) {
  int n = nums.size();
  vector<pair<int, int>>arr;
  for(int i=0; i<n; i++) 
    arr.push_back({nums[i], i});
  
  sort(arr.begin(), arr.end(), computeSort);

  vector<bool>vis(n, false);
  int swaps = 0;

  for(int i=0; i<n; i++){
    int cycle_size = 0, j = i;
    while(!vis[j]){
      vis[j] = true;
      j = arr[j].second;
      cycle_size++;
    }

    if(cycle_size>1) swaps+= (cycle_size-1);
  }
  return swaps;
}
};