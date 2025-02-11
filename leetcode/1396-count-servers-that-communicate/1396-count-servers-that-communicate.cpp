class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowIndex(m, 0);
        vector<int> colIndex(n, 0);

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    rowIndex[row] += 1;
                    colIndex[col] += 1;
                }
            }
        }

        int result = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && (rowIndex[row] > 1 || colIndex[col] > 1))
                    result++;
            }
        }

        return result;
    }
};