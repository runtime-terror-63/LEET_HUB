class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
          long long ans = 0;
        int i=0;
        vector<bool>vis(instructions.size(), false);
        while(i<instructions.size()){
            if(vis[i]) break;
            vis[i] = true;
            if(instructions[i]=="jump"){
            i = i + values[i];
            }else {
            ans += values[i];
            i = i+1;
            }
        }
        return ans;
    }
};