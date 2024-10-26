class Solution {
public:
    char nextGreatestLetter(vector<char>& letter, char target) {
         int low = 0, high = letter.size()-1;
        char ans = '0';
        while(low<=high){
            int mid = (low+high)>>1;
            if(letter[mid]>target){
            ans = letter[mid];
            high = mid-1;
            }else low = mid+1;
        }
        if(ans=='0') return letter[0];
        return ans;
    }
};