class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int>lastIndex(26, 0);
  for(int i=0; i<s.length(); i++){
    lastIndex[s[i]-'a'] = i;
  }        

  vector<int>res;

  int end = 0, start = 0;
  for(int i=0; i<s.length(); i++){
    end = max(end, lastIndex[s[i]-'a']);

    if(end==i){
      res.push_back(i-start+1);
      start = i+1;
    }
  }
  return res; 
    }
};