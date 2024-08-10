class Solution {
public:

    void dfs(vector<vector<int>> &matrix, int i, int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size() || matrix[i][j] == 1){
            return;
        }

        matrix[i][j] = 1;       //visited

        dfs(matrix, i+1, j);
        dfs(matrix, i-1, j);
        dfs(matrix, i, j+1);
        dfs(matrix, i, j-1);
    }   
    
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int region = 0;

        //create a 3*3 matrix to handle slashes
        vector<vector<int>> matrix(row*3, vector<int> (col*3, 0));

        //Populate the matrix based on '/' and '\\' in the original grid
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        //apply DFS
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    dfs(matrix, i, j);
                    region += 1;
                }
            }
        }

        return region;
    }
};