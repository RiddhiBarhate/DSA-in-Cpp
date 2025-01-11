class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n == k)
            return true;

        if(n < k)
            return false;

        vector<int> arr(26, 0);

        for(char& ch : s){
            arr[ch - 'a']++;
        }

        int oddCount = 0;
        for(int i = 0; i < 26; i++){
            if(arr[i] % 2 != 0)
                oddCount++;
        }

        if(oddCount <= k)
            return true;
        else
            return false;
    }
};