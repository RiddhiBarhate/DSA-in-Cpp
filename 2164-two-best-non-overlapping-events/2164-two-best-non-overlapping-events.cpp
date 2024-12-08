class Solution {
public:
    int n;

    int binary(vector<vector<int>>& events, int endTime){
        int l = 0, r = n - 1;
        int result = n;

        while(l <= r){
            int mid = l + (r-l) / 2;
            if(events[mid][0] > endTime){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count, vector<vector<int>>& dp){
        if(count == 2 || i >= n)
            return 0;

        if(dp[i][count] != -1)
            return dp[i][count];

        int nextValidIndex = binary(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count+1, dp);

        int skip = solve(events, i+1, count, dp);

        return dp[i][count] = max(take, skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));

        sort(events.begin(), events.end());

        int count = 0;
        return solve(events, 0, count, dp);
    }
};