class Solution {
public:

    bool isCheck(string &word1, string &word2)
    {
        if (word2.size() - word1.size() != 1)
            return false;

        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size())
        {
            if (word1[i] == word2[j])
            i++;
            j++;
        }
        return i == word1.size();
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
            { return a.size() < b.size(); });
        int maxi = 1;
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev_ind = 0; prev_ind < i; prev_ind++)
            {
            if (isCheck(words[prev_ind], words[i]))
            {
                dp[i] = max(dp[i], dp[prev_ind] + 1);
            }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};