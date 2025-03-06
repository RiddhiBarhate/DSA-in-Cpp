class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2);
        vector<bool> num(pow(n,2) + 1, false);
        num[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int number = grid[i][j];
                if(num[number] == false){
                    num[number] = true;
                }else{
                    res[0] = grid[i][j];
                }
            }
        }

        for(int i = 0; i < num.size(); i++){
            if(num[i] == false){
                res[1] = i;
                break;
            }
        }

        return res;
    }
};