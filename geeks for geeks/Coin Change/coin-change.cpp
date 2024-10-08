//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int solve(int coins[], int N, int sum, int index, vector<vector<long long int>>& dp) {
        
       if(sum < 0 || index >= N)
        return 0;
        
       if(sum == 0)
        return 1;
        
       if(dp[index][sum] != -1)
        return dp[index][sum];
        
       long long int include = solve(coins, N, sum - coins[index], index, dp);
       
       long long int exclude = solve(coins, N, sum, index+1, dp);
       
       dp[index][sum] = include + exclude;
       
       return dp[index][sum];
       
    }
  
    long long int count(int coins[], int N, int sum) {
       
        vector<vector<long long int>> dp(N, vector<long long int>(sum+1, -1));
        return solve(coins, N, sum, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends