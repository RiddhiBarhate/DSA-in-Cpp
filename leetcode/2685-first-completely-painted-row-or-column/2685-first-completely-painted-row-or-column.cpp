class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            int val = arr[i];
            mp[val] = i;
        }

        int minIndex = INT_MAX;
        //check for each row
        for(int row = 0; row < m; row++){
            int lastIdx = INT_MIN;

            for(int col = 0; col < n; col++){
                int val = mat[row][col];
                int idx = mp[val];
                lastIdx = max(idx, lastIdx); 
            }
            minIndex = min(minIndex, lastIdx);
        }

        //check for each col
        for(int col = 0; col < n; col++){
            int lastIdx = INT_MIN;

            for(int row = 0; row < m; row++){
                int val = mat[row][col];
                int idx = mp[val];
                lastIdx = max(idx, lastIdx); 
            }
            minIndex = min(minIndex, lastIdx);
        }

        return minIndex;
    }
};