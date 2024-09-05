class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            if(count == 0 && s[i] == ' ')   //end space
                continue;
            else if(count > 0 && s[i] == ' ')   //space before last word
                break;
            else
                count++;
        }
        return count;
    }
};