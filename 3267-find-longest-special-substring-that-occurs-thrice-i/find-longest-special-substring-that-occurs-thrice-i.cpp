#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int maximumLength(string s) {
        int answer = 0;
        vector<vector<int>> frequency(26);

        populateFrequency(s, frequency);
        answer = calculateMaxLength(frequency);

        if (answer == 0) answer = -1;
        return answer;
    }

private:
    void populateFrequency(const string& str, vector<vector<int>>& frequency) {
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (j < str.size() && str[j] == str[i]) j++;
            frequency[str[i] - 'a'].push_back(j - i);
            i = j;
        }
    }

    int calculateMaxLength(const vector<vector<int>>& frequency) {
        int ml = 0;
        for (const auto& x : frequency) {
            if (x.empty()) continue;
            vector<int> sortedFrequency = x;
            sort(sortedFrequency.begin(), sortedFrequency.end());

            int size = sortedFrequency.size();
            ml = max(ml, sortedFrequency.back() - 2);

            if (size > 1) {
                ml = max(ml, min(sortedFrequency[size - 1] - 1, sortedFrequency[size - 2]));
            }

            if (size > 2) {
                ml = max(ml, sortedFrequency[size - 3]);
            }
        }
        return ml;
    }
};