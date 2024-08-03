#include <bits/stdc++.h> 
int maxOne(vector<vector<int>> &arr)
{
	int N = arr.size();
	int M = arr[0].size();
	int max_row = -1;
	int j = M-1;

	for(int i = 0; i < N; i++){

		while(j >= 0 && arr[i][j] == 1){
			j--;
			max_row = i;
		}
		
	}

	return max_row;
}
