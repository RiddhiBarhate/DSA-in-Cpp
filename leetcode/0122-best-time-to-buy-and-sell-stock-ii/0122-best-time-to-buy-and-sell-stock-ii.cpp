class Solution {
public:

    /*int solveMem(int index, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(index == n)
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        
        if(buy){
            int buykaro = -prices[index] + solveMem(index+1, 0, prices, dp);
            int skipkaro = 0 + solveMem(index+1, 1, prices, dp);
            profit = max(buykaro, skipkaro);
        }
        else{
            int sellkaro = +prices[index] + solveMem(index+1, 1, prices, dp);
            int skipkaro = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(sellkaro, skipkaro);
        }

        dp[index][buy] = profit;
        return dp[index][buy];
    }*/

    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        int profit = 0;
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    int buykaro = -prices[index] + dp[index+1][0];
                    int skipkaro = 0 + dp[index+1][1];
                    profit = max(buykaro, skipkaro);
                }
                else{
                    int sellkaro = +prices[index] + dp[index+1][1];
                    int skipkaro = 0 + dp[index+1][0];
                    profit = max(sellkaro, skipkaro);
                }
                dp[index][buy] = profit;
            }
        }
 
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        //int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int> (2, -1));
        //return solveMem(0, 1, prices, dp);

        return solveTab(prices);
    }
};