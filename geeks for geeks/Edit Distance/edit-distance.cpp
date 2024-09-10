//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(string &s, string &t, int i, int j, vector<vector<int>>& dp){
        
        if(i == s.length())
            return t.length() - j;

        if(j == t.length())
            return s.length() - i;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX;
        
        if(s[i] == t[j]){
            ans = solve(s, t, i+1, j+1, dp);
        }
        else{
            int insert = 1 + solve(s, t, i, j+1, dp);
            int remove = 1 + solve(s, t, i+1, j, dp);
            int replace = 1 + solve(s, t, i+1, j+1, dp);
            
            ans = min(insert, min(remove, replace));
        }
        return dp[i][j] = ans;
        
    }
  
    int editDistance(string s, string t) {
        
        vector<vector<int>> dp(s.length()+1, vector<int> (t.length()+1, -1));
        return solve(s, t, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends