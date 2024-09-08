int binary(vector<int>& arr,int s,int e, int key)
{
	int start=s;
	int end=e;
	
	while(start<=end)
	{
		int mid=start+((end-start)/2);
		if(arr[mid]==key)
		{
			return mid;
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
	return -1;
}

int pivot(vector<int>& arr,int n)
{
	int s=0, e=n-1;
	while(s<e)
	{
		int m = s+(e-s)/2;
		if(arr[m]>=arr[0])
		{
			s=m+1;
		}
		else
		{
			e=m;
		}	
	}
	return s;
}


int search(vector<int>& arr, int n, int k)
{
    int getpivot=pivot(arr,n);
    if(k>=arr[getpivot] && k<=arr[n-1])
    {
        binary(arr,getpivot,n-1,k);
    }
    else
    {
        binary(arr,0,getpivot-1,k);
    }
}