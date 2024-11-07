class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxSetBits = 0;

        for(int bitPos = 0; bitPos < 24; bitPos++){
            int count = 0;
            for(int &num : candidates){
                if((num & (1 << bitPos)) != 0){
                    count++;
                }
            }
            maxSetBits = max(maxSetBits, count);
        }
        return maxSetBits;
    }
};