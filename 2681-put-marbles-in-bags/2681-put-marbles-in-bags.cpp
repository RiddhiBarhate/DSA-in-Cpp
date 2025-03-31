class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<int> pairsum(n-1, 0);
        for(int i = 0; i < n-1; i++){
            pairsum[i] = weights[i] + weights[i+1];
        }

        sort(pairsum.begin(), pairsum.end());

        long minsum = 0;
        long maxsum = 0;
        for(int i = 0; i < k-1; i++){
            minsum += pairsum[i];
            maxsum += pairsum[n-i-2];
        }

        return maxsum - minsum;
    }
};