class Solution {
public:

    int solve(int currCountA, int pasteCount, vector<vector<int>>& dp, int n){
        if(currCountA == n)
            return 0;

        if(currCountA > n)
            return 1000;

        if(dp[currCountA][pasteCount] != -1)
            return dp[currCountA][pasteCount];

        int copyPaste = 1 + 1 + solve(currCountA + currCountA, currCountA, dp, n);

        int paste = 1 + solve(currCountA + pasteCount, pasteCount, dp, n);

        return dp[currCountA][pasteCount] = min(copyPaste, paste);

    }

    int minSteps(int n) {
        if(n == 1)
            return 0;

        vector<vector<int>> dp(1000, vector<int> (1000, -1));

        return 1 + solve(1, 1, dp, n);      //+1 because 1st copy is mandatory
    }
};