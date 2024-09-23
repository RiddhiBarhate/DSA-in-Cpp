class Solution {
public:

    int solve(int i, string& s, unordered_set<string>& st, int& n, vector<int>& dp){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int result = 1 + solve(i+1, s, st, n, dp);

        for(int j = i; j < n; j++){
            string curr = s.substr(i, j-i+1);
            if(st.count(curr)){
                result = min(result, solve(j+1, s, st, n, dp));
            }
        }

        return dp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(n+1, -1);

        return solve(0, s, st, n, dp);
    }
};