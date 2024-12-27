class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int score = 0;
        int max_till_now = values[0];

        for(int i = 1; i < n; i++){
            int x = values[i] - i;
            int y = max_till_now;

            score = max(score, x+y);
            max_till_now = max(max_till_now, values[i] + i);
        }

        return score;
    }
};