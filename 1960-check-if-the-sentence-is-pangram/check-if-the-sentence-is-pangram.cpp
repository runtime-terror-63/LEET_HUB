class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int>mpp;
        for(auto it : sentence)mpp[it]++;

        return mpp.size()==26;
    }
};