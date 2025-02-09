class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;

        unordered_map<int, int> numCnt;
        numCnt[nums[0]] = 1; 

        for(int j = 1; j < n; j++){
            int cntOfNumsj = numCnt[nums[j] - j];
            int totalPairs = j;

            int badPairs = totalPairs - cntOfNumsj;

            count += badPairs;

            numCnt[nums[j] - j]++;
        }

        return count;
    }
};