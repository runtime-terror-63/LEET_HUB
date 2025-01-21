class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int>st;
        for(int i=0; i<pushed.size(); i++){
            st.push(pushed[i]);

            while(!st.empty() && popped[j]==st.top()){
                st.pop();
                j++;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};