class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2){
        int n = str1.length();
        
        string s1 = str2.substr(0, n);
        string s2 = str2.substr(str2.length()-n, n);

        return s1 == str1 && s2 == str1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }

        return count;
    }
};