class Solution {
public:
    int minMaxDifference(int num) {
         //11891
        string s = to_string(num);
        string s2 = to_string(num);
        char c, d;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='9') {
            c = s[i];
            break;
            }
        }  //1

        for(int i=0; i<s2.length(); i++){
            if(s2[i]!='0') {
            d = s2[i];
            break;
            }
        }  // 1

        //1
        for(int i=0; i<s.length(); i++){
            if(s[i]==c) s[i] = '9';
        }

            for(int i=0; i<s2.length(); i++){
            if(s2[i]==d) s2[i] = '0';
        }

        // cout<<s<<" "<<s2<<endl;
        return stoi(s) - stoi(s2);
    }
};