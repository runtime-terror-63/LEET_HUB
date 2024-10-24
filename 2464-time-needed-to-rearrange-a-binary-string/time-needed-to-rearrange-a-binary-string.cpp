class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int target = 0;
        while (true)
        {
            bool chnages = false;
            for (int i = 0; i < n; i++)
            {
            if (s[i] == '0' && s[i + 1] == '1')
            {
                swap(s[i], s[i + 1]);
             i++;
                chnages = true;
            }
            }

        if (chnages) target++;
        else break;
    }
    return target;
    }
};