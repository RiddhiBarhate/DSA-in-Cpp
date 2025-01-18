class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int XOR = 0;

        if(n % 2 != 0){
            for(int& num : nums2){
                XOR ^= num;
            }
        }

        if(m % 2 != 0){
            for(int& num : nums1){
                XOR ^= num;
            }
        }

        return XOR;
    }
};