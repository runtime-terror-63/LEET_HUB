class Solution {
public:
    string removeDuplicates(string s, int k) {
    int n = s.length();
    stack<pair<char, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top().first != s[i])
        st.push({s[i], 1});
        else
        {
        auto prev = st.top().second;
        st.pop();
        st.push({s[i], prev + 1});
        }

        if (st.top().second == k)
        st.pop();
    }

    string temp = "" ;
    while (!st.empty())
    {
       auto curr = st.top();
       st.pop();
       while(curr.second--){
        temp += curr.first;
       }
    }
    reverse(temp.begin(), temp.end());
    return temp;
    }
};