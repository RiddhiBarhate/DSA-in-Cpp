class Solution {
public:
    int maxScore(string s) {
        int n = s.length() - 1;
        int zero = 0; 
        int one = 0;
        int score = INT_MIN;
        
        for(int i = 0; i <= n-1; i++){
            if(s[i] == '0')
                zero++;

            for(int j = i+1; j <= n; j++){
                if(s[j] == '1')
                    one++;
            }
            score = max(score, zero + one);
            one = 0;
        }

        return score;
    }
};