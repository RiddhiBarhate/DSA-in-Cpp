class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];
        int maxOfPrevSegment = INT_MIN;

        for(int i = 1; i < n; i++){
            if(__builtin_popcount(nums[i]) == numOfSetBits){    //they belong to same grp
                maxOfSegment = max(maxOfSegment, nums[i]);  //find max of current segment
                minOfSegment = min(minOfSegment, nums[i]);  //find min of current segment
            }
            else{   //element belongs to new segment
                if(minOfSegment < maxOfPrevSegment)
                    return false;

                //update the prev segment's max
                maxOfPrevSegment = maxOfSegment;

                //new segment started
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        //final check for proper segment arrangement
        if(minOfSegment < maxOfPrevSegment)
            return false;

        return true;
    }
};