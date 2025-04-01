class Solution {
public:

    long long solve(int n, vector<vector<int>>& questions, vector<long long>& dp, int i){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        long long include = questions[i][0] + solve(n, questions, dp, i + questions[i][1] + 1);
        long long exclude = solve(n, questions, dp, i+1);

        return dp[i] = max(include, exclude);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);

        return solve(n, questions, dp, 0);
    }
};