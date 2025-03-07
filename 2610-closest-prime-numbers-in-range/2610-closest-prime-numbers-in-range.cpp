class Solution {
public:

    bool isPrime(int num){
        if(num == 1)
            return false;
        
        for(int i = 2; i*i <= num; i++){
            if(num % i == 0)
                return false;
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;

        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                prime.push_back(i);
            }
        }

        int mindiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < prime.size(); i++){
            int diff = prime[i] - prime[i-1];
            if(diff < mindiff){
                mindiff = diff;
                result = {prime[i-1], prime[i]};
            }
        }

        return result;
    }
};