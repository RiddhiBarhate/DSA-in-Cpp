class Solution {
public:

    /*int solveMem(int x, int y, vector<int>& arr,  map<pair<int,int>, int>& maxi, vector<vector<int>>& dp){
        int n = arr.size();
        if(x == y)
            return 0;

        if(dp[x][y] != -1)
            return dp[x][y];

        int ans = INT_MAX;
        for(int i=x; i<y; i++){
            ans = min(ans, maxi[{x,i}] * maxi[{i+1,y}] + solveMem(x, i, arr, maxi, dp) + solveMem(i+1, y, arr, maxi, dp));
            dp[x][y] = ans;
        }
        return dp[x][y];
    }*/

    int solveTab(vector<int>& arr,  map<pair<int,int>, int>& maxi){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int x=n; x>=0; x--){
            for(int y=1; y<n; y++){
                int ans = INT_MAX;
                if(x == y)
                    continue;
                else{
                    for(int i=x; i<y; i++){
                        ans = min(ans, maxi[{x,i}] * maxi[{i+1,y}] + dp[x][i] + dp[i+1][y]);
                        dp[x][y] = ans;
                    }
                }
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int> maxi;
        int n = arr.size();
        //vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        //return solveMem(0, n-1, arr, maxi, dp);

        return solveTab(arr, maxi);
    }
};