class Solution {
public:
    const int M = 1e9 + 7;

    int solve(int low, int high, int zero, int one, int length, vector<int>& dp){
        if(length > high)
            return 0;

        if(dp[length] != -1)
            return dp[length];

        bool addOne = false;
        if(length >= low && length <= high)
            addOne = true;

        int app_zero = solve(low, high, zero, one, length + zero, dp);
        int app_one = solve(low, high, zero, one, length + one, dp);

        return dp[length] = (addOne + app_zero + app_one) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int length = 0;
        vector<int> dp(high+1, -1);
        return solve(low, high, zero, one, length, dp);
    }
};