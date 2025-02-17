class Solution {
public:

    int count;
    void solve(vector<int>& freq){
        count++; 

        for(int i = 0; i < 26; i++){
            if(freq[i] == 0)
                continue;

            freq[i]--;      //DO
            solve(freq);      //UNDO
            freq[i]++;      //EXPLORE

        }
    }

    int numTilePossibilities(string tiles) {
    
        vector<int> freq(26, 0);
        for(char &ch : tiles){
            freq[ch - 'A']++;
        }

        count = 0;
        solve(freq);

        return count - 1; //empty string is not allowed
    }
};