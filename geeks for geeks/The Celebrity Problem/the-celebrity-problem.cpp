//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


// ********ALGORITHM*******
// 1. Push all elements in stack
// 2. Pop top 2 elements(a & b)
// 3. If a knows b, means a is not celebrity push b back to stack
// 4. If b knows a push a
// 5. If stack size == 1 verify if he is a celebrity or not
// 6. Check celebrity row = 0
// 7. Check celebrity column = 1 except the diagonal one

class Solution 
{
    
    private:
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack<int> s;
        
        //step 1
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        //step 2
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            //step 3 & 4
            if(knows(M, a, b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //step 5
        int ans = s.top();   //remaining last element
        
        //step 6
        int zeroCount = 0;
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        if(zeroCount != n)
            return -1;
        
        //step 7
        int oneCount = 0;
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
            
       return ans; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends