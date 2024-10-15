class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long score = 0;

        while(k > 0){
            int num = pq.top();
            score += num;

            num = ceil(num/3.0);
            pq.pop();
            pq.push(num);

            k--;
        }

        return score;
    }
};