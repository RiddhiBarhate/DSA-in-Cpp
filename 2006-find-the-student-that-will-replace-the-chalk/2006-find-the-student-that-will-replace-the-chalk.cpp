class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        
        //total chalk for one cycle
        for(int c : chalk){
            totalChalk += c;
        }

        //to reduce k after completing n cycles
        k %= totalChalk;

        //to check which index remains left
        for(int i = 0; i < chalk.size(); i++){
            if(k >= chalk[i])
                k -= chalk[i];
            else
                return i;
        }
        return -1;
    }
};