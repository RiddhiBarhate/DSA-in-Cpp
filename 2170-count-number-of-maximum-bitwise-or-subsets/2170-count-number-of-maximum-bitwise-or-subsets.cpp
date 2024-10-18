class Solution {
public:

    int countSubsets(int idx, int currOR, vector<int>& nums, int maxOR){
        //base case
        if(idx == nums.size()){
            if(currOR == maxOR)
                return 1;
            return 0;
        }

        int include = countSubsets(idx+1, currOR | nums[idx], nums, maxOR);

        int exclude = countSubsets(idx+1, currOR, nums, maxOR);

        return include + exclude;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int & num : nums){
            maxOR |= num;
        }

        int currOR = 0;
        return countSubsets(0, currOR, nums, maxOR);
    }
};