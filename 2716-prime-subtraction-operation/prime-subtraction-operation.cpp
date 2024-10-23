class Solution {
public:
    vector<int> getPrimes(int N) {
    vector<int> primes(N + 1, 0);

    for (int i = 2; i * i <= N; i++) {
        if (primes[i] == 0) {
            for (int j = i * i; j <= N; j += i) {
                primes[j] = 1;
            }
        }
    }

    vector<int> res;
    for (int i = 2; i <= N; i++) {
        if (primes[i] == 0)
            res.push_back(i);
    }

    return res;
}

int getLastInd(const vector<int>& primes, int val) {
    int ind = -1, l = 0, r = primes.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (primes[mid] < val) {
            ind = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ind;
}

bool isValid(const vector<int>& primes, const vector<int>& nums) {
    int prev = -1;
    for (int num : nums) {
        int ind = getLastInd(primes, num);
        bool flag = false;

        for (int j = ind; j >= 0; j--) {
            if (num - primes[j] > prev) {
                prev = num - primes[j];
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (prev >= num)
                return false;
            else
                prev = num;
        }
    }
    return true;
}

bool primeSubOperation(const vector<int>& nums) {
    vector<int> primes = getPrimes(1000);
    return isValid(primes, nums);
}
};
