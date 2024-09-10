//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>> &mat,int n,int m,int &maxi) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int r = dp[i][j+1];
                int d = dp[i+1][j];
                int dig = dp[i+1][j+1];
                if(mat[i][j]==1) {
                    dp[i][j] = 1+min(r,min(d,dig));
                    maxi = max(maxi,dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi = 0;
        solve(mat,n,m,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends