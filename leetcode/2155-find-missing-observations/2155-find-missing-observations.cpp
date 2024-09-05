class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        //sum of rolls
        int totalRolls = 0;
        for(int i = 0; i < rolls.size(); i++){
            totalRolls += rolls[i];
        }

        //Remaining rolls sum
        int remainingRolls = (mean * (rolls.size() + n)) - totalRolls;

        if(remainingRolls > 6*n || remainingRolls < n)
            return {};

        vector<int> ans;
        int full = remainingRolls / n;
        int extra = remainingRolls % n;

        for(int i = 0; i < n; i++){    
            if(extra > 0)
                ans.push_back(full + 1);
            else
                ans.push_back(full);

            extra = max(0, extra - 1);
        }

        return ans;
    }
};