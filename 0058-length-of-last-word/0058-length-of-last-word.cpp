class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            if(count == 0 && s[i] == ' ')
                continue;
            else if(count > 0 && s[i] == ' ')
                break;
            else
                count++;
        }
        return count;
    }
};