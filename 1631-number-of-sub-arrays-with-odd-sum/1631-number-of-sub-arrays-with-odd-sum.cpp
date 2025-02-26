class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};