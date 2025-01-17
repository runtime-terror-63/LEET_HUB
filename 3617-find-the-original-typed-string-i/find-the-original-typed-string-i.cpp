class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1, totalcnt = 1;
        int n = word.size();
        for(int i = 1; i<n; i++){
            if(word[i]==word[i-1]) {
                cnt++;
                cout<<cnt<<endl;
            }
            else {
                if(cnt>1) totalcnt += (cnt-1);
               // cout<<"t- "<<totalcnt<<endl;
                cnt = 1;
            }
        }

       // cout<<"next "<<cnt<<endl;
        if(cnt>1) totalcnt += cnt-1;
        return totalcnt;
    }
};