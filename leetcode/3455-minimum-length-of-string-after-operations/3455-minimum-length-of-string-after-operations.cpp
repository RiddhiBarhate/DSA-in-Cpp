class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        vector<int> arr(26, 0);
        for(char& ch : s){
            arr[ch - 'a']++;
        }

        int result = 0;
        int i = 0;
        while(i < 26){
            
            if(arr[i] >= 3){
                arr[i] -= 2; 
            }
            else{
                result += arr[i];
                i++;
            }
        }
        return result;
    }
};