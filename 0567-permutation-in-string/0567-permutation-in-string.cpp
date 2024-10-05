class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m)
            return false;

        //Approach 1 : Brute force
        /*sort(s1.begin(), s1.end());

        for(int i = 0; i <= m-n; i++){
            string temp = s2.substr(i, n);

            sort(temp.begin(), temp.end());

            if(temp == s1)
                return true;
        }

        return false;*/

        //Approach 2 : Sliding Window
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        for(char& ch : s1){
            s1_freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        while(j < m){
            s2_freq[s2[j] - 'a']++;

            if((j-i+1) > n){
                s2_freq[s2[i] - 'a']--;
                i++;
            }

            if(s1_freq == s2_freq)
                return true;

            j++;
        }
        return false;
    }
};