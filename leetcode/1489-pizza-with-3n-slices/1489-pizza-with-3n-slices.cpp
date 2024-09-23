//Approach 1 - Using memoization

/*class Solution {
public:
    int solve(int index, int endindex, vector<int>& slices, int n, vector<vector<int>>& dp){
        
        if(n == 0 || index > endindex)
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];

        int include = slices[index] + solve(index+2, endindex, slices, n-1, dp);
        int exclude = 0 + solve(index+1, endindex, slices, n, dp);

        return dp[index][n] = max(include, exclude);
        
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int> (n,-1));
        int case1 = solve(0, n-2, slices, n/3, dp1);
        vector<vector<int>> dp2(n, vector<int> (n,-1));
        int case2 = solve(1, n-1, slices, n/3, dp2);
        return max(case1, case2);
    }
};*/

//Approach 2 - space optimization

class Solution {
public:

int solve_space_opti(vector<int> slices)
{
    int k = slices.size();
     vector<int>prev1(k+2,0);
     vector<int>curr1(k+2,0);
     vector<int>next1(k+2,0);

     vector<int>prev2(k+2,0);
     vector<int>curr2(k+2,0);
     vector<int>next2(k+2,0);

     for(int index = k-2;index >=0;index--)
     {
        for(int n = 1;n<=k/3;n++)
        {
           int take = slices[index] + next1[n-1];
           int nottake = 0 + curr1[n];
           prev1[n]= max(take,nottake);
        }
        next1=curr1;
        curr1=prev1;
     }
     int case1=curr1[k/3];

        for(int index = k-1;index>=1;index--)
     {
        for(int n = 1;n<=k/3;n++)
        {
           int take = slices[index] + next2[n-1];
           int nottake = 0 + curr2[n];
           prev2[n]= max(take,nottake);
        }
        next2=curr2;
        curr2=prev2;
     }
     int case2=curr2[k/3];

     return max(case1,case2);

}
    int maxSizeSlices(vector<int>& slices) {
        return solve_space_opti(slices);
    }
};