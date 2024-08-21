class Solution {
public:

    int solve(int l, int r, string &s, vector<vector<int>> &dp){
        if(l == r)
            return 1;

        if(l > r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int i = l + 1;
        while(i <= r && s[i] == s[l]){
            i++;
        }

        if(i == r + 1)
            return 1;

        int ans1 = 1 + solve(i, r, s, dp);

        int ans2 = INT_MAX;
        for(int j = i; j <= r; j++){
            if(s[j] == s[l]){
                ans2 = min(ans2, solve(i, j-1, s, dp) + solve(j, r, s, dp));
            }
        }

        return dp[l][r] = min(ans1, ans2);

    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve(0, n-1, s, dp);
    }
};