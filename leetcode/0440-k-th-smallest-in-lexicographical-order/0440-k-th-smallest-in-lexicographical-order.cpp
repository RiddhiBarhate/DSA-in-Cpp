class Solution {
public:

    int Count(long curr, long next, long n){
        int count = 0;
        while(curr <= n){
            count += (next - curr);

            curr *= 10;
            next *= 10;

            next = min(next, n+1);
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;        //since we start from 1

        while(k > 0){
            int count = Count(curr, curr+1, n);
            if(count <= k){
                curr++;
                k -= count;  //skipping the elemnts
            }
            else{
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};