class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int result = 0;

        for(int i = 1; i < arrays.size(); i++){
            int currmin = arrays[i].front();
            int currmax = arrays[i].back();

            result = max({result, abs(currmin - maxi), abs(currmax - mini)});

            maxi = max(maxi, currmax);
            mini = min(mini, currmin);
        } 

        return result;
    }
};