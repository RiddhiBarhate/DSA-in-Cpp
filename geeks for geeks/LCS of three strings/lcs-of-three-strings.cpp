//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int solve(vector<vector<vector<int>>>& dp, string& A, string& B, string& C, int n1, int n2, int n3, int i, int j, int k){
            //base case
            if(i==n1 || j==n2 || k==n3)
                return 0;
                
            if(dp[i][j][k] != -1)
                return dp[i][j][k];
            
            int ans = INT_MIN;
            
            if(A[i] == B[j] && B[j] == C[k]){
                ans = 1 + solve(dp, A, B, C, n1, n2, n3, i+1, j+1, k+1);
            }
            else{
                int ans1 = solve(dp, A, B, C, n1, n2, n3, i+1, j, k);
                int ans2 = solve(dp, A, B, C, n1, n2, n3, i, j+1, k);
                int ans3 = solve(dp, A, B, C, n1, n2, n3, i, j, k+1);
                
                ans = max(ans1, max(ans2, ans3));
            }
            return dp[i][j][k] = ans;
        }

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>> dp(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, -1)));
            return solve(dp, A, B, C, n1, n2, n3, 0, 0, 0);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends