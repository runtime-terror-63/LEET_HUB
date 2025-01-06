#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> operationReq(n, 0);
        vector<int> requiredSum(n + 1, 0);
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--) {
            requiredSum[i] = requiredSum[i + 1] + cnt;

            if (boxes[i] == '1') {
                cnt++;
            }
        }

        cnt = 0;
        int prevTotal = 0;

        for (int i = 0; i < n; i++) {
            operationReq[i] = prevTotal + requiredSum[i];

            if (boxes[i] == '1') {
                cnt++;
            }

            prevTotal += cnt;
        }

        return operationReq;
    }
};
