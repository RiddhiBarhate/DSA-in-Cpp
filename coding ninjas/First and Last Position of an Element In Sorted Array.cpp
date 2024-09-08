#include <bits/stdc++.h> 
int first(vector<int>& arr,int n, int key)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		if(arr[mid]==key)
		{
			ans=mid;
			end=mid-1;
		}
		else if(arr[mid]<key)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
		
	}
	return ans;
}

int last(vector<int>& arr,int n, int key)
{
	int start=0;
	int end=n-1;
	int ans=-1;
	
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		if(arr[mid]==key)
		{
			ans=mid;
			start=mid+1;
		}
		else if(arr[mid]<key)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
		
	}
	return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
   pair<int, int> p;
   p.first=first(arr,n,k); 
   p.second=last(arr,n,k); 

   return p;
}