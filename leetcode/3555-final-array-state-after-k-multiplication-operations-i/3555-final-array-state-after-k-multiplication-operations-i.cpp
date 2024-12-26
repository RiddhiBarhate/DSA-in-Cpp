class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        vector<int> result(n);

        while(k--){
            int minEle = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            minEle = minEle * multiplier;
            pq.push({minEle, idx});
        }

        while(!pq.empty()){
            int ele = pq.top().first;
            int idx = pq.top().second;
            result[idx] = ele;
            pq.pop();
        }

        return result;
    }
};