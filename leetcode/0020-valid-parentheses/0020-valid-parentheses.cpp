class Solution {
public:
    bool isValid(string s) {
        stack<char> paranthesis;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                paranthesis.push(s[i]);
            }
            else{
                if(!paranthesis.empty()){
                    if((paranthesis.top() == '(' && s[i] == ')') ||
                    (paranthesis.top() == '{' && s[i] == '}') ||
                    (paranthesis.top() == '[' && s[i] == ']')){
                            paranthesis.pop();
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
        }

        if(paranthesis.empty())
            return 1;
        else
            return 0;
    }
};