class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        int ans1 = 1, ans2 = 1;

        for(int i = 1; i < n; i++){
            if(nums[i-1] > nums[i]){
                dec++;
                ans1 = max(ans1, dec);
            }
            else{
                dec = 1;
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i]){
                inc++;
                ans2 = max(ans2, inc);
            }
            else{
                inc = 1;
            }
        }


        return max(ans1, ans2);
    }
};