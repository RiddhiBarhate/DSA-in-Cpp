class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int black = 0;

        for(char& ch : s){
            if(ch == '1'){
                black++;
            }
            else{
                swap += black;
            }
        }

        return swap;
    }
};