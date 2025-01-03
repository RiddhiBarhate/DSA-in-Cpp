class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cumSum(n);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            cumSum[i] = sum;
        }

        int split = 0;
        for(int i = 0; i < n-1; i++){
            if(cumSum[i] >= (cumSum[n-1] - cumSum[i])){
                split++;
            }
        }

        return split;
    }
};