#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> sortedSum;

	int n = arr.size();
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += arr[j];
			if(sortedSum.size() < k){
				sortedSum.push(sum);
			}
			else{
				if(sum > sortedSum.top()){
					sortedSum.pop();
					sortedSum.push(sum);
				}
			}
		}
	}

	return sortedSum.top();
}