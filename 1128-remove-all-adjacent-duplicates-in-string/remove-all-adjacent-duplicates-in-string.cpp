class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else if(st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }

        while(!st.empty()){
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};