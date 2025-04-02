class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long value = 0;

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    long long num = (long long)(nums[i] - nums[j]) * nums[k];
                    value = max(value, num);
                }
            }
        }

        if(value < 0)
            return 0;

        return value;
    }
};