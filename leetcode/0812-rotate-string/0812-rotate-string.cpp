class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m)
            return false;

        int count = 0;
        for(int count = 0; count < m; count++){
            rotate(s.begin(), s.begin()+1 ,s.end());     
            //it says that I want (s.begin()+1)th character to become the first character now. i.e. shifting left by one

            if(s == goal)
                return true;
        }

        return false;
    }
};