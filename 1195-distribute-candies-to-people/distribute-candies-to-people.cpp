class Solution {
public:
// Input: candies = 7, num_people = 4
// Output: [1,2,3,1]

// Input: candies = 10, num_people = 3
// Output: [5,2,3]
vector<int> distributeCandies(int candies, int num_people) {
        vector<int>arr(num_people, 0);
        int i = 0, give = 1;
        for(;;){
            if(candies==0) break;
            if(i==num_people) i = 0;
                if(candies>=give){
                arr[i] += give;
                candies -= give;
                }else{
                arr[i] += candies;
                candies = 0;
                }
            give++;
            i++;
        }
        return arr;
    }
};