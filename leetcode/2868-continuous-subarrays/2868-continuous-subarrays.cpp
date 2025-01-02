class Solution {
public:
    #define P pair<int, int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<P> maxheap;
        priority_queue<P, vector<P>, greater<P>> minheap;
        long long count = 0;
        int i = 0, j = 0;

        while(j < n){
            maxheap.push({nums[j], j});
            minheap.push({nums[j], j});

           while(maxheap.top().first - minheap.top().first > 2){
                i++;

                while(!maxheap.empty() && maxheap.top().second < i){
                    maxheap.pop();
                }

                while(!minheap.empty() && minheap.top().second < i){
                    minheap.pop();
                }
           }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};