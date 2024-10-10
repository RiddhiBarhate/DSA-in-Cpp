class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // Step 1: Build a decreasing stack of indices
        for(int i = 0; i < n; i++){
            if(st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }

        int ramp = 0;

        // Step 2: Traverse from the end and find maximum width ramp
        for(int j = n-1; j >=0; j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                ramp = max(ramp, j - st.top());
                st.pop();
            }
        }

        return ramp;
    }
};