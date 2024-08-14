class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //Approach 1
        /*int n = nums.size();
        
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
        return diff[k-1];*/

        //Approach 2
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n-1] - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, j = 0;
            
            // Use two pointers to count pairs with distance <= mid
            for (int i = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= mid) j++;
                count += j - i - 1;
            }
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};