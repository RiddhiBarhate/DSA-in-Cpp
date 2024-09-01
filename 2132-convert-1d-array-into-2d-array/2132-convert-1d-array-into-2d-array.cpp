class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int> (n));

        if((m * n) != original.size())
            return {};

        //Approach 1
        /*int k = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = original[k];
                k++;
            }
        }*/

        //Approach 2
        //(i/col = row, i%col = col)
        int k = 0;
        for(int i = 0; i < original.size(); i++){
            ans[i/n][i%n] = original[k];
            k++;
        }

        return ans;
    }
};