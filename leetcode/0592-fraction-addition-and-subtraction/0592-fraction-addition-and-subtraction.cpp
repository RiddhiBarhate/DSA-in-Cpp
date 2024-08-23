class Solution {
public:
    string fractionAddition(string expression) {
        int i = 0;
        int n = expression.length();
        int nume = 0;
        int deno = 1;

        while(i < n){
            int currnumo = 0;
            int currdeno = 0;

            bool isNeg = (expression[i] == '-');

            if(expression[i] == '+' || expression[i] == '-'){
                i++;
            }

            while(i < n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currnumo = (currnumo * 10) + val;
                i++;
            }  
            i++;     //to skip divisor(/)

            if(isNeg == true){
                currnumo *= -1;
            }

            while(i < n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currdeno = (currdeno * 10) + val;
                i++;
            }

            nume = (nume * currdeno) + (currnumo * deno);
            deno = deno * currdeno;
        }

        //to simplify
        int gcd = abs(__gcd(nume, deno));
        nume /= gcd;
        deno /= gcd; 

        return to_string(nume) + "/" + to_string(deno);
    }
};