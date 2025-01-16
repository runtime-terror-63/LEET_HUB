class Solution {
public:
bool hasMatch(string s, string p) {
  int x = p.find("*");
  string a = p.substr(0, x);
  string b = p.substr(x+1);

  int y = s.find(a);
  int z = s.find(b, y+a.length());
 // cout<<y<<" "<<z <<endl;

  return (z!=-1 && y!= -1);
}
};