class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
          string str = "";
            int cnt = 0;
            vector<string>ds;
            for(int i=0; i<s.size(); i++){
                str+=s[i];
                if(str.size()==k){
                ds.push_back(str);
                str.clear();
                }
            }
            if(!str.empty()){
                while(str.size()!=k){
                str.push_back(fill);
                }
                ds.push_back(str);
            }
            return ds;
    }
};