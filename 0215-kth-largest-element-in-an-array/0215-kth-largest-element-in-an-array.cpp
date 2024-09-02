class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> largeElements;

        for(auto ele : nums){
            largeElements.push(ele);
        }

        for(int i = 0; i < k-1; i++){
            largeElements.pop();
        }

        return largeElements.top();
    }
};