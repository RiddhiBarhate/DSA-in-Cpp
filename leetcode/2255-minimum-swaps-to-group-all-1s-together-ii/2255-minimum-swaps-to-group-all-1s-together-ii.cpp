class Solution {
public:
    int minSwaps(vector<int>& nums) {

        //window size = count of 1
        int windowsize = 0;
        for(int num : nums){
            windowsize += num;
        }

        //Edge cases
        if(windowsize == 0 || windowsize == nums.size())
            return 0;

        int currZero = 0;
        //count zero in first window
        for(int i = 0; i < windowsize; i++){
            if(nums[i] == 0)
                currZero++;
        }

        int start = 0;
        int end = windowsize - 1;
        int n = nums.size();
        int minZero = currZero;
        //check for other windows
        while(start < n){
            //if removed number is 0, decrement currZero
            if(nums[start] == 0){
                currZero--;
            }
            start++;
            end++;
            //if added number is 0, increment currZero
            if(nums[end % n] == 0){   //for circular array
                currZero++;
            }

            minZero = min(minZero, currZero);
        }

        return minZero;
    }
};