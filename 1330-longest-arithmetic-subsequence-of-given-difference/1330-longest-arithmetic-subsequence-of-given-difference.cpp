class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;

        for(int i=0; i<arr.size(); i++){
            int temp = arr[i] - difference;
            int tempans = 0;

            //check ans exist for temp or not
            if(dp.count(temp))
                tempans = dp[temp];

            //update current ans
            dp[arr[i]] = 1 + tempans;

            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};