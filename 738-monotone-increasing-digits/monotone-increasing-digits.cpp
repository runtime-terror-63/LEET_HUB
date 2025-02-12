class Solution {
public:
    int monotoneIncreasingDigits(int n) {
          string s = to_string(n); 
  int ind = s.length();

  if(s.length()==1) return stoi(s);
  for(int i = s.length()-1; i>0; i--){
    if(s[i]<s[i-1]){
      ind = i;
      s[i-1]--;

    }
  }

  for(int i = ind; i<s.length(); i++){
    s[i] = '9';
  }
 return stoi(s);
    }
};