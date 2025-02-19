class Solution {
public:
void solve(int n, int k, string st, vector<string>& res) {
    if (st.size() == n) {
        res.push_back(st);
        return;
    }
    for (char ch : {'a', 'b', 'c'}) {
        if (st.empty() || st.back() != ch) 
            solve(n, k, st + ch, res); 
    }
}

string getHappyString(int n, int k) {
    vector<string> res;
    solve(n, k, "", res);
    if (k > res.size()) return "";
    return res[k - 1]; 
}
};