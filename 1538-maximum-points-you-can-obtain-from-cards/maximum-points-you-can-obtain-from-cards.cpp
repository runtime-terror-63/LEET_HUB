class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowStart = 0;
        int maxSum = 0;
        int currSum = 0;
         int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int card_size = cardPoints.size()-k;
        if(card_size==0)return total_sum;
       
        for (int windowEnd = 0; windowEnd < cardPoints.size(); windowEnd++){
            currSum += cardPoints[windowEnd];
            if(windowEnd-windowStart+1==card_size){
                maxSum = max(maxSum, total_sum-currSum); 
                currSum -= cardPoints[windowStart];
                windowStart++;   
            }
        }
        return maxSum;
    }
};