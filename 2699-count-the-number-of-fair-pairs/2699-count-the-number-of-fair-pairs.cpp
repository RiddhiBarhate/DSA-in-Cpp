class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long result = 0;

        for(int i = 0; i < n; i++){
            int idx = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int x = idx - 1 - i;

            idx = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();
            int y = idx -1 - i;

            result += (y - x);
        }
        return result;
    }
};