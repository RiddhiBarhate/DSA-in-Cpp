class Solution {
public:

    int solve(vector<vector<int>>& pairs, vector<int> dp){
        int n = pairs.size();

        if(n == 1)
            return 1;

        int ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = dp[j] + 1;
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n+1, 1);

        sort(pairs.begin(), pairs.end());

        return solve(pairs, dp);
    }
};