#include <bits/stdc++.h> 
int missingNumber(vector<int> &arr, int n) 
{
    int diff1 = abs(arr[0] - arr[1]);
    int diff2 = abs(arr[1] - arr[2]);
    int diff = min(diff1, diff2);

    for(int i = 0; i < arr.size(); i++){
        int next_term = arr[i] + diff;
        if(next_term != arr[i+1])
            return next_term;
    }
    return 0;
}