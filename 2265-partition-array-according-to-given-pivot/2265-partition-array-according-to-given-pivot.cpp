class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, 0);

        int less = 0, pcnt = 0, greater = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot)
                less++;
            else if(nums[i] > pivot)
                greater++;
            else
                pcnt++;
        }

        int i = 0; 
        int l = 0, p = less, g = n-greater;
        while(i < n){
            if(nums[i] < pivot){
                res[l] = nums[i];
                l++;
            }
            else if(nums[i] == pivot){
                res[p] = nums[i];
                p++;
            }
            else if(nums[i] > pivot){
                res[g] = nums[i];
                g++;
            }

            i++;
        }

        return res;
    }
};