#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int left=0,mid=0,right=n-1;
   for(int i=0;i<n;i++)
   {
      if(arr[mid]==0)
      {
         swap(arr[left],arr[mid]);
         left++;
         mid++;
      }
      else if(arr[mid]==1)
      {
         mid++;
      }
      else
      {
         swap(arr[mid],arr[right]);
         right--;
      }
   }
}