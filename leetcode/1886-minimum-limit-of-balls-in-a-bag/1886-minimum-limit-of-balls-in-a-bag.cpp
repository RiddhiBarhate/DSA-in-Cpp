class Solution {
public:

    bool isPossible(vector<int>& nums, int maxOperations, int mid){
        int totalOp = 0;

        for(int i = 0; i < nums.size(); i++){
            int op = nums[i] / mid;
            if(nums[i] % mid == 0)
                op -= 1;

            totalOp += op;
        }

        if(totalOp <= maxOperations)
            return true;
        else
            return false;

    }

    int minimumSize(vector<int>& nums, int maxOperations) {
       
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int mid;
        int result;

        while(l <= r){
            mid = l + (r-l) / 2;

            if(isPossible(nums, maxOperations, mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};