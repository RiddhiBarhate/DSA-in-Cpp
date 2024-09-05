class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i >= 0; i--){
            if(digits[i] != 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);   //to insert 1 at beginning for ex 99
        return digits;
    }
};