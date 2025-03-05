class Solution {
public:
    long long coloredCells(int n) {
        long long cells = 1;

        for(int i = 1; i <= n; i++){
            cells += 4 * (i-1);
        }

        return cells;
    }
};