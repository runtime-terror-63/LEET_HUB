class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        while(n > 0) {
            vec.push_back(n % 10);
            n /= 10;
        }

        int maxPro = 0;
        for(int i = 0; i < vec.size(); i++) {
            for(int j = i+1; j < vec.size(); j++) {
                int pro = vec[i] * vec[j];
                maxPro = max(maxPro, pro);
            }
        }
        return maxPro;
    }
};
