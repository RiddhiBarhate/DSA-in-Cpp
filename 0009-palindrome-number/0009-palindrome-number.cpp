class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        long long reversed = 0;
        int num = x;

        while(num > 0){
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }

        return (reversed == x);
    }
};