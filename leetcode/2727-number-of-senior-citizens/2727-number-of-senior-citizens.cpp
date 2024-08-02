class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string& detail : details){
        
            int val1 = detail[11] - '0';
            int val2 = detail[12] - '0';

            int age = val1 * 10 + val2;

            if(age > 60)
                count++;
        }
        return count;
    }
};