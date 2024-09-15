class Solution {
public:
    
    string getValue(string s) {
        int sum = 0, val;
    
        for(auto ch : s) {
   
            val = ch - '0';
        
            sum += val;
        }
       
        return to_string(sum);
    }

    int getLucky(string s, int k) {
        string sum;

        for(auto ch : s) {
            int val = ch - 'a' + 1;
       
            sum += to_string(val);
        }

        while(k--) {
           
            sum = getValue(sum);
        }

       
        return stoi(sum);
    }
};