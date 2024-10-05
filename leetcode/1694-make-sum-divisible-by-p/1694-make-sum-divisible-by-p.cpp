class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum = (sum + nums[i]) % p;
        }

        int target = sum % p;

        if(target == 0)
            return 0;

        unordered_map<int, int> mp;
        int curr = 0;
        mp[0] = -1;

        int result = n;
        for(int i = 0; i < n; i++){
            curr = (curr + nums[i]) % p;

            int remaining = (curr - target + p) % p;
            if(mp.find(remaining) != mp.end())
                result = min(result, i - mp[remaining]);

            mp[curr] = i;
        }

        return result == n ? -1 : result;
    }
};