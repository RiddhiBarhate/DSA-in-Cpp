class Solution {
public:

    int solveMem(int index, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(index == n)
            return 0;

        if(k == 0)
            return 0;

        if(dp[index][buy][k] != -1)
            return dp[index][buy][k];

        int profit = 0;
        
        if(buy){
            int buykaro = -prices[index] + solveMem(index+1, 0, k, prices, dp);
            int skipkaro = 0 + solveMem(index+1, 1, k, prices, dp);
            profit = max(buykaro, skipkaro);
        }
        else{
            int sellkaro = +prices[index] + solveMem(index+1, 1, k-1, prices, dp);
            int skipkaro = 0 + solveMem(index+1, 0, k, prices, dp);
            profit = max(sellkaro, skipkaro);
        }

        dp[index][buy][k] = profit;
        return dp[index][buy][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solveMem(0, 1, k, prices, dp);
    }
};