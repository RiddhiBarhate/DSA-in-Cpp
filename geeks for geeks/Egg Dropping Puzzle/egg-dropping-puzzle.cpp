//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int egg, int floor, vector<vector<int>>& dp){
        if(egg == 0)
            return 0;
        if(egg == 1 || floor == 0 || floor == 1)
            return floor;
            
        if(dp[egg][floor] != -1)
            return dp[egg][floor];
            
        int mini = INT_MAX;
        
        for(int k=1; k<=floor; k++){
            int moves = max(solve(egg, floor - k, dp), solve(egg-1, k - 1, dp));
            mini = min(mini, moves);
        }
        return dp[egg][floor] = mini + 1;
    }
    
    
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends