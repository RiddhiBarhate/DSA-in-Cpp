class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> endpoint;
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size(); i++){
        
           if(!endpoint.empty() && endpoint.top() < intervals[i][0]){
                endpoint.pop();  
            }

            endpoint.push(intervals[i][1]);
        }

        return endpoint.size();
    }
};