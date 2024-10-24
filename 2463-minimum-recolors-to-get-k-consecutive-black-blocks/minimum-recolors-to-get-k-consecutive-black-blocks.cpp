class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int minSum = 1e9;
    int windowStart = 0;
    int windowSum = 0;

    for (int windowEnd = 0; windowEnd < n; windowEnd++)
    {
        if (blocks[windowEnd] == 'B')
        windowSum++;
        if (windowEnd - windowStart + 1 == k)
        {
            minSum = min(minSum, k - windowSum);
            if(blocks[windowStart]=='B')
            windowSum--;
            windowStart++;
        }
    }
    return minSum;
    }
};