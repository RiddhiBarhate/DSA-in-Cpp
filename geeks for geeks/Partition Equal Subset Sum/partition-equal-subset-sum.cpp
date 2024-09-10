//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solve(int index, int N, int arr[], int target, vector<vector<int>>& dp){
        if(target < 0 || index >= N)
            return 0;
        
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)
            return dp[index][target];
            
        bool include = solve(index+1, N, arr, target - arr[index], dp);
        bool exclude = solve(index+1, N, arr, target, dp);
        
        return dp[index][target] = (include || exclude);
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        
        if(sum & 1)
            return 0;
            
        sum = sum/2;
        
        vector<vector<int>> dp(N+1, vector<int> (sum+1, -1));
        return solve(0, N, arr, sum, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends