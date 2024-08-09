class Solution {
public:

    bool isMagical(vector<vector<int>>& grid, int r, int c){
        //check bet 1-9 and distinct
        unordered_set<int> st;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num))
                    return false;
                else
                    st.insert(num);
            }
        }

        //Sum
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        //check each row and column sum
        for(int i = 0; i < 3; i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum)
                return false;

            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum)
                return false;
        }

        //check diagonal
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum)
            return false;

        //check antidiagonal
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid.size();
        int count = 0;

        for(int i = 0; i <= row-3; i++){    //last 2 rows or col cannot form 3*3 grid
            for(int j = 0; j <= col-3; j++){
                if(isMagical(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};