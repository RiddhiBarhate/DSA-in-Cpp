class Solution {
public:
    string removeOccurrences(string s, string part) {

        //Approach 1
        /*while(s.length()!=0 && s.find(part)<s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;*/

        //Approach 2
        int partLength = part.length();
        char partEnd = part.back();
        string result;

        for(char ch : s){
            result.push_back(ch);

            if(ch == partEnd && result.length() >= partLength){
                if(result.substr(result.length() - partLength) == part){
                    result.erase(result.length() - partLength);
                }
            }
        }
        return result;
    }
};