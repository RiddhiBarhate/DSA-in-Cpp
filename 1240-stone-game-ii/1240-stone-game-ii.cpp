class Solution {
public:
    //Alice = 1;
    //Bob = 0;

    int dp[2][101][101];
    int solveForAlice(vector<int>& piles, int person, int i, int M){
        //base case
        int n = piles.size();
        if(i >= n)
            return 0;

        if(dp[person][i][M] != -1)
            return dp[person][i][M];

        int stones = 0;
        int result = (person == 1) ? -1 : INT_MAX;

        for(int x = 1; x <= min(2*M, n-i); x++){
            stones += piles[i+x-1];

            if(person == 1){        //Alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(x,M)));
            }
            else{       //Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(x,M)));
            }
        }

        return dp[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solveForAlice(piles, 1, 0, 1);
    }
};