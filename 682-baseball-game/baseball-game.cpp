class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=="D"){
                auto curr = st.top()*2;
                st.push(curr);
            }else if(s[i]=="C"){
                st.pop();
            }else if(s[i]=="+"){
                auto curr = st.top();
                st.pop();
                auto curr1 = st.top();
                auto curr2 = curr + curr1;
                st.push(curr);
                st.push(curr2);
            }else st.push(stoi(s[i]));
        }

        int sum = 0;
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            sum += (int)curr;
        }
        return sum;
    }
};