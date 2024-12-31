class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        int n = days.size();
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int one = costs[0] + solve(days, costs, i+1, dp);

        int max_day = days[i] + 7;
        int j = i;
        while(j < n && days[j] < max_day){
            j++;
        }
        int seven = costs[1] + solve(days, costs, j, dp);

        max_day = days[i] + 30;
        j = i;
        while(j < n && days[j] < max_day){
            j++;
        }
        int thirty = costs[2] + solve(days, costs, j, dp);

        return dp[i] = min({one, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        return solve(days, costs, 0, dp);
    }
};