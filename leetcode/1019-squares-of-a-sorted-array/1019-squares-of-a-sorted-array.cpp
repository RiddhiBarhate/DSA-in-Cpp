class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }

        vector<int> square(nums.size(), 0);
        int s = 0, e = nums.size()-1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[s] >= nums[e]){
                square[i] = nums[s];
                s++;
            }
            else{
                square[i] = nums[e];
                e--;
            }
        }
        return square;
    }
};