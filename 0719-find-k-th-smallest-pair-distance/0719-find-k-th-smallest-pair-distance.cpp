class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> diff;
        int i = 0;
        int sum = 0;

        while(i < nums.size()){
            for(int j = i+1; j < nums.size(); j++){
                sum = abs(nums[j] - nums[i]);
                diff.push_back(sum);
            }
            i++;
        }

        nth_element(diff.begin(), diff.begin() + (k-1), diff.end());    //sort only till kth value and return that value
        return diff[k-1];
    }
};