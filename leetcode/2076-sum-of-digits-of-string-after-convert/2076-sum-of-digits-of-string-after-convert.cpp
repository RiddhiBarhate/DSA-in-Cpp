class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char ch : s){
            int char_int = ch - 'a' + 1;
            num += to_string(char_int);
        }

        int sum = 0;
        while(k > 0){
            sum = 0;
            for(char ch : num){
                sum += ch - '0';
            }
            num = to_string(sum);
            k--;
        }

        return stoi(num);
    }
};