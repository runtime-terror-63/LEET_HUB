class Solution {
public:
    int maxDiff(int num) {
 string s1 = to_string(num);
  string s2 = to_string(num);
  char ch1=0, ch2=0;
  for(int i=0; i<s1.length(); i++){
    if(s1[i]!='9'){
      ch1 = s1[i];
      break;
    }
  }

  for(int i=0; i<s2.length(); i++){
    if(s2[i]!='1' && s2[i]!='0'){
      ch2 = s2[i];
      break;
    }
  }

  for(int i=0; i<s1.length(); i++){
    if(s1[i]==ch1) s1[i] = '9';
  }

  char elm2 = s2[0];
  char replace = '1';
  if(elm2=='1'){
    for(int k = 1; k<s2.length(); k++){
      if(s2[k]!='0' && s2[k] !='1'){
        elm2 = s2[k];
        replace = '0';
        break;
      }
    }
  }

  for(int k=0; k<s2.length(); k++){
    if(s2[k]==elm2) s2[k] = replace;
  }
 // cout<<ch1<<" "<<ch2<<endl;
 // cout<<s1<<" "<<s2<<endl;
  int n1 = stoi(s1), n2 = stoi(s2); 
  return n1-n2;
    }
};