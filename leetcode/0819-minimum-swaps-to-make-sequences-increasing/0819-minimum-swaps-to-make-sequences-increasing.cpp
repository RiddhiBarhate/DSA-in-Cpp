class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2 ,  int index ,  int swapped ,  vector<vector<int>> &dp){

        // base case 
        if(index ==  nums1.size()){
            return 0 ;
        }

        int ans =  INT_MAX ;
        int prev1 =  nums1[index-1] ;
        int prev2 =   nums2[index-1 ];\

        if(dp[index][swapped] != -1){
            return dp[index][swapped] ;
        }

        if(swapped){
            swap(prev1 , prev2) ;

        }

        // NO SWAPP
        if(nums1[index] > prev1 && nums2[index] >prev2){
            ans =  solve(nums1 , nums2 , index+1 , 0 , dp);
        }

        // SWAPPED
        if(nums1[index] > prev2  && nums2[index] > prev1){
            ans = min(ans ,  1+solve(nums1 , nums2 , index+1 , 1,dp)) ;
        }
        return dp[index][swapped] = ans ;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        // st1 : add -1 at the begninng of both the arrays 
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);
        int n =  nums1.size() ;
        bool swapped =  0 ;

        vector<vector<int>> dp(n , vector<int> (2,-1)) ;
        return solve(nums1, nums2 , 1 , swapped , dp);        
    }
};