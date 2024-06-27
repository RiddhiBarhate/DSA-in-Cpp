//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        queue<int> q1;
        queue<int> q2;
        
        for(int i=0; i<n/2; i++){
            int element = q.front();
            q1.push(element);
            q.pop();
        }
        
        while(!q.empty()){
            int element = q.front();
            q2.push(element);
            q.pop();
        }
        
        vector<int> ans;
        while(!q1.empty()){
            int element = q1.front();
            ans.push_back(element);
            q1.pop();
            
            element = q2.front();
            ans.push_back(element);
            q2.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends