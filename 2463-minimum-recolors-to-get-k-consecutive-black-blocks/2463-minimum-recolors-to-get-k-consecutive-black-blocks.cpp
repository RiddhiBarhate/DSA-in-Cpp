class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(); 
        int op = INT_MAX;

        for(int i = 0; i <= n-k; i++){
            int count = 0;
            for(int j = i; j-i+1 <= k; j++){
                if(blocks[j] == 'W'){
                    count++;
                }
            }
            op = min(op, count);
        }

        return op;
    }
};