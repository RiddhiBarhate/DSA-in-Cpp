class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(isalpha(s[i]))
                st.push(s[i]);
            else if(!st.empty())
                st.pop();
        }

        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};