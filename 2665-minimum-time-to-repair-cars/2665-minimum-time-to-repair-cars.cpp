class Solution {
public:

    typedef long long ll;

    bool isPossible(vector<int>& ranks, int cars, ll mid){
        ll carFixed = 0;

        for(int i = 0; i < ranks.size(); i++){
            carFixed += sqrt(mid / ranks[i]);
        }

        return carFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        ll l = 1;
        ll maxR = *max_element(ranks.begin(), ranks.end());
        ll r = maxR * cars * cars;
        ll result = -1;

        while(l <= r){
            ll mid = l + (r - l)/ 2;

            if(isPossible(ranks, cars, mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
};