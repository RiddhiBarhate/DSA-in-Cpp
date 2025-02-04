class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i]){
                sum += nums[i];
            }
            else{
                ans = max(ans, sum);
                sum = nums[i];
            }
        }

        return max(ans, sum);
    }
};