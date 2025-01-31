class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;

        if(n == 1)
            return nums[0];
            
        Arrays.sort(nums);
        int count = 0;
        int maxCount = 0;
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                count++;
                if(maxCount < count){
                    maxCount = count;
                    ans = nums[i];
                }
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
}