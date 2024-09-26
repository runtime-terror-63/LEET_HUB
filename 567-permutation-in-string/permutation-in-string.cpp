#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mpp;  
        for (auto it : s1) 
            mpp[it]++;
        
        int windowStart = 0;
        int k = s1.length();  
        int cnt = mpp.size(); 
        for (int windowEnd = 0; windowEnd < s2.length(); windowEnd++) {
            // Check if the current character in s2 is in s1's frequency map
            if (mpp.find(s2[windowEnd]) != mpp.end()) {
                mpp[s2[windowEnd]]--;
               
                if (mpp[s2[windowEnd]] == 0) 
                    cnt--;
            }

            if (windowEnd - windowStart + 1 == k) {
               
                if (cnt == 0) return true;

               
                if (mpp.find(s2[windowStart]) != mpp.end()) {
                    mpp[s2[windowStart]]++;
                    if (mpp[s2[windowStart]] == 1) 
                        cnt++;
                }

                windowStart++;  // Move the start of the window forward
            }
        }
        return false;  // No permutation found
    }
};