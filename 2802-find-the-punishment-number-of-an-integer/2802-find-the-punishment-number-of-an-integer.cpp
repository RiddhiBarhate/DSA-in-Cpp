class Solution {
public:

    bool check(int sq, int currSum, int num){
        if(sq == 0)
            return currSum == num;

        return check(sq/10, currSum + sq%10, num) ||
                check(sq/100, currSum + sq%100, num) ||
                check(sq/1000, currSum + sq%1000, num) ||
                check(sq/10000, currSum + sq%10000, num);
    }

    int punishmentNumber(int n) {
        int punish = 0;

        for(int i = 1; i <= n; i++){
            int sq = i * i;

            if(check(sq, 0, i) == true){
                punish += sq;
            }
        }

        return punish;
    }
};