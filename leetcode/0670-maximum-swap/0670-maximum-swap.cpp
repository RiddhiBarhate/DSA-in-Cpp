class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();

        vector<int> maxRight(10, -1);

        for(int i = 0; i < n; i++){
            int idx = str[i] - '0';
            maxRight[idx] = i;
        }

        for(int i = 0; i < n; i++){
            int currDigit = str[i] - '0';

            for(int digit = 9; digit > currDigit; digit--){
                if(maxRight[digit] > i){
                    swap(str[i], str[maxRight[digit]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};