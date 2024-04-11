class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);

        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Dynamic programming
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // To reach the top, we can either come from the last or second-to-last step
        dp[n] = min(dp[n - 1], dp[n - 2]);

        return dp[n];
    }
};
