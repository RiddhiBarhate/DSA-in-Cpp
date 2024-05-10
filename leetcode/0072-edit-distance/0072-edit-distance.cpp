class Solution {
public:

    int solveMem(string& a, string &b, int i, int j, vector<vector<int>>& dp){
        //base cases
        //if word 1 is small than word 2
        if(i == a.length())
            return b.length() - j;

        //if word 2 is small than word 1
        if(j == b.length())
            return a.length() - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if(a[i] == b[j]){
            ans = solveMem(a, b, i+1, j+1, dp);
        }
        else{
            //insert
            int insert = 1 + solveMem(a, b, i, j+1, dp);

            //delete
            int delet = 1 + solveMem(a, b, i+1, j, dp);

            //replace
            int replace = 1 + solveMem(a, b, i+1, j+1, dp);

            ans = min(insert, min(delet, replace));
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, -1));
        return solveMem(word1, word2, 0, 0, dp);
    }
};