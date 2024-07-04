//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool cmp(pair<Item, double> a, pair<Item, double> b){
        return a.second > b.second;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<pair<Item, double>> v;
        
        for(int i=0; i<n; i++){
            double perunit = (1.0 * arr[i].value) / arr[i].weight;
            pair<Item, double> p = make_pair(arr[i], perunit);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double max_value = 0;
        for(int i=0; i<n; i++){
            if(v[i].first.weight <= w){
                max_value += v[i].first.value;
                w = w - v[i].first.weight;
            }
            else{
                max_value += w * v[i].second;
                w = 0;
            }
        }
        return max_value;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends