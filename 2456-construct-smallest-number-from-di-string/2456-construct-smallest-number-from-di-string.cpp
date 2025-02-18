class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string result = "";
        stack<int> st;

        int count = 1, i = 0;
        while(count <= n+1){
            st.push(count);

            if(pattern[i] == 'I' || i >= n){

                while(!st.empty()){
                    result.push_back(st.top() + '0');
                    st.pop();
                }
            }

            count++;
            i++;
        }

        return result;
    }
};