class Solution {
public:
    char findKthBit(int n, int k) {
        //base case
        if(n == 1)
            return '0';

        int length = pow(2, n) - 1;

        if(k < ceil(length / 2.0))
            return findKthBit(n-1, k);
        else if(k == ceil(length / 2.0))
            return '1';     //middle value is always 1
        else{
            char ch = findKthBit(n-1, length-(k-1));    //handle reverse
            return (ch == '0') ? '1' : '0';       //invert char
        }
    }
};