#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;

    //Approach 1
    /*for(int i = 0; i < kArrays.size(); i++){
        for(int j = 0; j < kArrays[i].size(); j++){
            ans.push_back(kArrays[i][j]);
        }    
    }

    sort(ans.begin(), ans.end());*/

    //Approach 2 (Optimized)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < k; i++){
        vector<int> arr = kArrays[i];

        for(auto ele : arr){
            pq.push(ele);
        }
    }

    while(pq.size() > 0){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}