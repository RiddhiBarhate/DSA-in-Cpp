class Solution {
public:

    int getSum(int n){
        int sum = 0;

        while(n > 0){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        vector<int> digit(82, 0);

        for(int i = 0; i < n; i++){
            int digitSum = getSum(nums[i]);

            if(digit[digitSum] > 0)
                result = max(result, nums[i] + digit[digitSum]);
                
            digit[digitSum] = max(digit[digitSum], nums[i]);
        }

        return result;
    }
};