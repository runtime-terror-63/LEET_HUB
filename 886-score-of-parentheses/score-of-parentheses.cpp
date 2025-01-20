class Solution {
public:
    int cnt = 0;
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') st.push(0);
            else{
                //int cnt = 0;
                int top = st.top();
                st.pop();
                //cout<<i<<st.top()<<endl;
                int curr = st.top();
                st.pop();
                if(top==0) st.push(curr+1);
                else st.push(2*top +curr);
               // else st.push(2*curr+1);
                
            }
        }   
        return st.top();
    }
};