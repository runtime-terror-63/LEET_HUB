class Solution {
public:

    int solve(int ind, vector<int> &prices, vector<vector<int>> &special, vector<int> &needs)
{
    int n = prices.size();
    int s_offer = special.size();

    // base case:
    bool canTake = true;
    if (ind == s_offer)
    {
        int totalCost = 0;
        for (int i = 0; i < n; i++)
        {
        totalCost += needs[i] * prices[i];
        }
        return totalCost;
    }

    for (int i = 0; i < n; i++)
    {
        if (needs[i] < special[ind][i])
        {
        canTake = false;
        break;
        }
    }
    // we have to check take or non_take ->> ind+1
    int take = 1e9;
    if (canTake)
    {
        for (int i = 0; i < n; i++)
        {
        needs[i] -= special[ind][i];
        }

        take = special[ind][n] + solve(ind, prices, special, needs);
        for (int i = 0; i < n; i++)
        {
        needs[i] += special[ind][i];
        }
    }

    int not_take = solve(ind + 1, prices, special, needs);
    return min(take, not_take);
}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
       return solve(0, price, special, needs);
    }
};