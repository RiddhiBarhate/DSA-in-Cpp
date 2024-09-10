//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    const int MOD = 1e9+7;
    public:
    //Function to find the nth catalan number.
    int solve(int n)
    {
            
        vector<long long> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] = (dp[i] + (dp[j] * dp[i-j-1]) % MOD) % MOD;
            }
        }
        return dp[n];
        
    }
    
    int findCatalan(int n) 
    {
        return solve(n);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends