class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        map<char, int>mpp;

        int cnt = 1;
        for(auto i = 'a'; i<='h'; i++){
            mpp[i] = cnt;
            cnt++;
        }

       // for(auto it : mpp) cout<<it.first<<": "<<it.second<<endl;

        int col1 = mpp[coordinate1[0]];   
        int row1 = coordinate1[1] -'0' ;

        int col2 = mpp[coordinate2[0]];
        int row2 = coordinate2[1]-'0';

        
        bool temp1 = (row1+col1 )%2==0;
        bool temp2 = (row2+col2 )%2==0;

        return temp1==temp2;
    }
};