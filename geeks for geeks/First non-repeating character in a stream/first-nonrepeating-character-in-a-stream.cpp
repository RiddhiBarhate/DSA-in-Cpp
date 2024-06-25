//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		
		    //to keep count of each char
		    unordered_map<char, int> count;
		    queue<int> q;
		    string ans = "";
		    
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        
		        q.push(ch);
		        
		        count[ch]++;
		        
		        while(!q.empty()){
		            
		            if(count[q.front()] > 1){       //char is repeating
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());       //char is non-repeating
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends