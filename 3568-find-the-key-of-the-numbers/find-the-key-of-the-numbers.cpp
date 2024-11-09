class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
       vector<string>vec;
        int ans = 0;
        vec.push_back(to_string(num1));
        vec.push_back(to_string(num2));
        vec.push_back(to_string(num3));

        for(int i = 0; i<3; i++){
            for(int j = vec[i].size(); j<4; j++){
                vec[i].insert(vec[i].begin(), '0');
            }
          cout<<vec[i]<<endl;
        }
      //  return ans;
        string str;
        for(int i = 0; i<4; i++){
            char ch = min({vec[0][i], vec[1][i], vec[2][i]});
            str += ch;
        }

        //cout<<str<<endl;
        return stoi(str);
    }
};