//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> &m, int n){
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0 && (m[x][y]==1))){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, int n, int x, int y, vector<string>& ans, string path, vector<vector<int>> visited){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        int newx=x+1;
        int newy=y;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('D');
            solve(m,n,newx,newy,ans,path,visited);
            path.pop_back();
        }
        
         
        newx=x;
        newy=y-1;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('L');
            solve(m,n,newx,newy,ans,path,visited);
            path.pop_back();
        }
        
        newx=x;
        newy=y+1;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('R');
            solve(m,n,newx,newy,ans,path,visited);
            path.pop_back();
        }
        
        newx=x-1;
        newy=y;
        if(isSafe(newx, newy, visited, m, n)){
            path.push_back('U');
            solve(m,n,newx,newy,ans,path,visited);
            path.pop_back();
        }
        
        visited[x][y]=0; 
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        int x=0;
        int y=0;
        string path="";
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        solve(m,n,x,y,ans,path,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends