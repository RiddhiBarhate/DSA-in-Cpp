class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> leftans = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightans = diffWaysToCompute(expression.substr(i+1));

                for(int &x : leftans){
                    for(int &y : rightans){
                        if(expression[i] == '+')
                            result.push_back(x + y);
                        else if(expression[i] == '-')
                            result.push_back(x - y);
                        else if(expression[i] == '*')
                            result.push_back(x * y);
                    }
                }  
            }            
        }

        if(result.empty()){
            result.push_back(stoi(expression));
        }

        return result;
    }
};