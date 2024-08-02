class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp){
        //base case
        if(amount == 0)
            return 0;

        if(dp[amount] != -1)
            return dp[amount];

        int minCoins = INT_MAX;

        // Try each coin
        for (int coin : coins) {
            if (amount - coin >= 0) { // Ensure we do not go below zero
                int result = solve(coins, amount - coin, dp);
                if (result != INT_MAX) {
                    minCoins = min(minCoins, result + 1);
                }
            }
        }
        
        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
       
        vector<int> dp(amount+1, -1);
        int result = solve(coins, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};