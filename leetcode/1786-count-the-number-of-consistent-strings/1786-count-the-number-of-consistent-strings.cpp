class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(), allowed.end());
        int count = 0;

        for(string word : words){
            bool allChar = true;

            for(char ch : word){
                if(!st.count(ch)){          //count return 0 or 1
                    allChar = false;
                    break;
                }       
            }

            count += allChar;
        }

        return count;
    }
};