class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ele;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ele.push_back(grid[i][j]);
            }
        }

        sort(ele.begin(), ele.end());

        int n = ele.size();
        int mid = n/2;
        int median = ele[mid];

        int op = 0;
        for(int i = 0; i < n; i++){
            int diff = abs(ele[i] - median);
            if(diff % x != 0)
                return -1;

            op += diff / x;
        }


        return op;
    }
};