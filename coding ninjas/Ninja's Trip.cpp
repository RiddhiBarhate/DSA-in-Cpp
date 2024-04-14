int solve(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int i=n-1; i>=0; i--){

        //option 1
        int option1 = cost[0] + dp[i+1];

        //option 2
        int j;
        for(j=i; j<n && days[j]<days[i] + 7; j++);
        int option2 = cost[1] + dp[j];

        //option 3
        for(j=i; j<n && days[j]<days[i] + 30; j++);
        int option3 = cost[2] + dp[j];

        dp[i] = min(option1 ,min(option2, option3));

    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solve(n,days,cost);
}