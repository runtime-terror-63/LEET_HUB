class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int max_dis = 0;

        for(int i=0; i<n; i++){
            if(seats[i]==1){
                if(prev==-1)  max_dis = i;

                else max_dis = max(max_dis, (i-prev)/2);

                prev = i;
            } 
        }


        max_dis = max(max_dis, n-1-prev);

        return max_dis;
    }
};