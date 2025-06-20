class Solution {
public:

   bool isAnagram(unordered_map<char,int>& word1, unordered_map<char,int>& word2){
    return word1 == word2;
}
    vector<int> findAnagrams(string txt, string pat) {
    int n = txt.size();
    int k = pat.size();

    unordered_map<char, int> wordCnt;
    for (char c : pat)
        wordCnt[c]++;

    unordered_map<char, int> substrCnt;
    int windowStart = 0;
    vector<int>ds;

    for (int windowEnd = 0; windowEnd < n; windowEnd++) {
        char c = txt[windowEnd];
        substrCnt[c]++;

        if (windowEnd - windowStart + 1 == k) {
            if (isAnagram(wordCnt, substrCnt)) 
            ds.push_back(windowStart);

            char removeChar = txt[windowStart];
            substrCnt[removeChar]--;
            if (substrCnt[removeChar] == 0)
                substrCnt.erase(removeChar);

            windowStart++;
        }
    }

    return ds;
    }
};