class Solution {
public:

    bool canDistribute(int &mid, long long k, vector<int>& candies){
        int n = candies.size();

        for(int i = 0; i < n; i++){
            k -= candies[i] / mid;
        }

        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += candies[i];
        }

        if(sum < k)
            return 0;

        int maxC = *max_element(candies.begin(), candies.end());
        
        int l = 1, r = maxC, ans = 0;
        while(l <= r){
            int mid = l + (r-l) / 2;

            if(canDistribute(mid, k, candies)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};