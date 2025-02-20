class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for(int i = 0; i < n; i++){
            char ch = nums[i][i];

            if(ch == '0')
                result += '1';
            else
                result += '0';
        }

        return result;
    }
};