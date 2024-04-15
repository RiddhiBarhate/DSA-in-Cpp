// class Solution {
// public:
//     int solve(vector<int>& obstacles, int lane, int pos, vector<vector<int>> &dp){
//         int n = obstacles.size()-1;
//         if(pos == n)
//             return 0;

//         if(dp[lane][pos] != -1){
//             return dp[lane][pos];
//         }

//         if(obstacles[pos+1] != lane){
//             return solve(obstacles, lane, pos+1, dp);
//         }
//         else{
//             int ans = 1e9;
//             for(int i = 1; i<=3; i++){
//                 if(obstacles[pos] != i && lane != 1){
//                     ans = min(ans, 1+solve(obstacles, i, pos, dp));
//                 }
//                 dp[lane][pos] = ans;
//             }
//         return dp[lane][pos];    
//         }
//     }

//     int minSideJumps(vector<int>& obstacles) {
//         vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
//         return solve(obstacles,2,0,dp);
//     }
// };
// 
class Solution {
public:
    int minSideJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>dp1(n,n), dp2(n,n), dp3(n,n);
        dp1[0] = 1; dp2[0] = 0; dp3[0] = 1;

        for(int i=1; i<n; i++){
            if(arr[i-1] != 1 && arr[i] != 1) dp1[i] = dp1[i-1];
            if(arr[i-1] != 2 && arr[i] != 2) dp2[i] = dp2[i-1];
            if(arr[i-1] != 3 && arr[i] != 3) dp3[i] = dp3[i-1];

            dp1[i] = min({dp1[i], 1 + dp2[i], 1 + dp3[i]});
            dp2[i] = min({1 + dp1[i], dp2[i], 1 + dp3[i]});
            dp3[i] = min({1 + dp1[i], 1 + dp2[i], dp3[i]});
        }

        return min({dp1[n-1],dp2[n-1],dp3[n-1]});
    }
};