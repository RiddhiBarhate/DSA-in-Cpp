bool isPossible(vector<int> &boards, int k, int mid)
{
    int painter=1;
    int unit=0;
    for(int i=0;i<boards.size();i++)
    {
        if(unit+boards[i]<=mid)
        {
            unit+=boards[i];
        }
        else
        {
            painter++;
            if(painter>k || boards[i]>mid)
            {
                return false;
            }
            unit=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    for(int i=0;i<=boards.size();i++)
    {
        sum+=boards[i];
    }
    int e=sum;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossible(boards,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}