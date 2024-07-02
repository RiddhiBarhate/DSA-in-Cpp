//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        sort(candies, candies+N);
        
        int min_cost = 0;
        int buy = 0;
        int free = N-1;
        
        while(buy <= free){
            min_cost += candies[buy];
            buy++;
            free = free-K;
        }
        ans.push_back(min_cost);
        
        int max_cost = 0;
        buy = N-1;
        free = 0;
        
        while(buy >= free){
            max_cost += candies[buy];
            free = free+K;
            buy--;
        }
        ans.push_back(max_cost);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends