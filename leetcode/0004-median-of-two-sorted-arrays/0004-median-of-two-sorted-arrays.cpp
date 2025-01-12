class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> arr;

        for(int& num : nums1){
            arr.push_back(num);
        }

        for(int& num : nums2){
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());

        int len = arr.size();
        double median;
        if(len % 2 == 0){
            median = (arr[len/2] + arr[(len/2) - 1]) / 2.0;
        }
        else{
            median = arr[len/2];
        }

        return median;
    }
};