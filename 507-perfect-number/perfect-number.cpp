class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>perfectNum = {6, 28, 496, 8128, 33550336};

        for(auto it : perfectNum){
            if(it==num) return true;
        }
        return false;
    }
};