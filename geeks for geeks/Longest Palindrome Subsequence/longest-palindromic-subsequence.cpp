//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int solve(int i, int j, string &A, string &rev, vector<vector<int>> &dp){
        //base case
        if(i>=A.length() || j>=rev.length())
            return 0;       //individual character length
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(A[i] == rev[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, A, rev, dp);
        }
        else{
            int ans1 = solve(i+1, j, A, rev, dp);
            int ans2 = solve(i, j+1, A, rev, dp);
            
            return dp[i][j] = max(ans1, ans2);
        }
    }
    
    int longestPalinSubseq(string A) {
        //code here
        int n = A.length();
        string rev = A;
        reverse(rev.begin(), rev.end());
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return solve(0, 0, A, rev, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends