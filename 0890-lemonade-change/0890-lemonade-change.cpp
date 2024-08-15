class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        if(bills[0] != 5)
            return false;

        int countFive = 0;
        int countTen = 0;
        
        int i = 0;
        while(i < bills.size()){
            if(bills[i] == 5){
                countFive++;
            }
            else if(bills[i] == 10){
                if(countFive > 0){
                    countTen++;
                    countFive--;
                }
                else{
                    return false;
                }
                
            }
            else if(bills[i] == 20){
                if(countTen > 0 && countFive > 0){
                    countTen--;
                    countFive--;
                }
                else if(countFive >= 3){
                    countFive -= 3;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};