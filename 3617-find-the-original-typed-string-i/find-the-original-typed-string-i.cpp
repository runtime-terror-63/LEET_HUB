class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int totalCnt = 1;
        for(int i=1; i<word.size(); i++){
            if(word[i]==word[i-1]) cnt++;
            else {
             if(cnt>1) totalCnt+= cnt-1;
              cnt = 1;
            }
        }
       
        if(cnt>1) totalCnt+= cnt-1;

        return totalCnt;
    }
};