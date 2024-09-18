class Solution {
public:
    int splitNum(int num) {
        string str = "";
        str = to_string(num);
        sort(str.begin(), str.end());
        string num1 = "", num2 = "";

        for(int i = 0; i<str.length(); i+=2){
             num1 += str[i];
             num2 += str[i+1];
        }

        int val1 = stoi(num1);
        int val2 = stoi(num2);
        return val1+val2;

    }
};