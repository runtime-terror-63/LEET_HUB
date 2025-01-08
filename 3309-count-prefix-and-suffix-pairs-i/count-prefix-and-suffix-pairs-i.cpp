class Solution {
public:

    bool isPossible(string& str1, string str2){
        int n1 = str1.length(), n2 = str2.length();

        return str2.substr(0, n1) == str1 && str2.substr(n2-n1)==str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++)
              if(isPossible(words[i], words[j]))
                cnt++;
        }
        return cnt;
    }
};