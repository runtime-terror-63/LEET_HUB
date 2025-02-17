class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
   sort(pizzas.begin(), pizzas.end());
  int n = pizzas.size();
  int days = n/4;
  int l=n-1;
  long long sum = 0;
  for(int i=1; i<=days; i+=2){
    sum += pizzas[l];
    l--;
  }

  l--;

  for(int i=2; i<=days; i+=2){
    sum += pizzas[l];
    l-=2;
  }

  return sum;
    }
};