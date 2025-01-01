class Solution {
public:
    int maxScore(string s) {
        int zeroCnt = 0;
        int cnt=0;
        for(auto c : s){
            if(c=='1') cnt++;
        }

     ///   cout<<cnt<<endl;
        int oneCnt = cnt;
        int maxi = INT_MIN;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='0') zeroCnt++;
            if(s[i]=='1') oneCnt--;

            maxi = max(maxi, oneCnt+zeroCnt);
          //  cout<<maxi<<endl;
        }
        return maxi;
    }
};