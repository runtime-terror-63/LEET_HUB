class Solution {
public:
    string answerString(string word, int numFriends) {
        int maxSize = word.size() - (numFriends-1);
        int size = word.size();
        if(numFriends==1) return word;
        string ans = "";

        priority_queue<pair<char, int>>pq;
        for(int i=0; i<word.size(); i++) pq.push({word[i], i});

        while(pq.size()>0){
            auto [c, ind] = pq.top();
            pq.pop();

            string temp = "";
            for(int i = ind; i<min(size, maxSize+ind); i++) temp += word[i];

            if(ans < temp) ans = temp;
        }
        return ans;
    }
};