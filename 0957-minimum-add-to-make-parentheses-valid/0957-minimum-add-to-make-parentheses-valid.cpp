class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int closingBracket = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(!st.empty() && (s[i] == ')' && st.top() == '('))
                st.pop();
            else
                closingBracket++;
        }

        return st.size() + closingBracket;
    }
};