class Solution {
public:

    int solveTab(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        int profit = 0;
        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    int buykaro = -prices[index] + dp[index+1][0];
                    int skipkaro = 0 + dp[index+1][1];
                    profit = max(buykaro, skipkaro);
                }
                else{
                    int sellkaro = +prices[index] + dp[index+1][1] - fee;
                    int skipkaro = 0 + dp[index+1][0];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy] = profit;
            }
        }
 
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solveTab(prices, fee);
    }
};