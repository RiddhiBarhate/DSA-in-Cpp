//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

#define MOD 1000000007
class Solution
{
public:

    long long int solve(int n, vector<int>& dp){
        if (n == 0 || n == 1)
            return 1;
            
        if(dp[n] != -1)
            return dp[n];
            
        int single = solve(n-1, dp) % MOD;
        int pair = (n-1) * (solve(n-2, dp) % MOD) % MOD;
        
        long long int ans = (single + pair) % MOD;
        dp[n] = ans;
        
        return dp[n];
    }

    int countFriendsPairings(int n) 
    { 
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends