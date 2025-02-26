class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currmaxsum = nums[0];
        int currminsum = nums[0];
        
        int maxsubsum = nums[0];
        int minsubsum = 0;

        for(int i = 1; i < n; i++){
            currmaxsum = max(nums[i], currmaxsum + nums[i]);
            maxsubsum = max(maxsubsum, currmaxsum);

            currminsum = min(nums[i], currminsum + nums[i]);
            minsubsum = min(minsubsum, currminsum);
        }

        return max(abs(maxsubsum), abs(minsubsum));
    }
};