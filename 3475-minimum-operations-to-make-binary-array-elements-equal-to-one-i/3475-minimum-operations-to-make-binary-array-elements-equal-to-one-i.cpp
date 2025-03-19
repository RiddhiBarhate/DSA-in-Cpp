class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;

        for (int i = 0; i <= n - 3; i++) { // Ensure we can flip 3 elements
            if (nums[i] == 0) {
                // Flip nums[i], nums[i+1], nums[i+2]
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                flips++;
            }
        }

        // If there are remaining 0s that cannot be flipped, return -1
        for (int i = n - 2; i < n; i++) {
            if (nums[i] == 0) return -1;
        }

        return flips;
    }
};