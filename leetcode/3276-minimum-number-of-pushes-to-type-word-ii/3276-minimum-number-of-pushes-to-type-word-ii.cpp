class Solution {
public:
    int minimumPushes(string word) {
        //count the frequency of each char
        int arr[26];
        for(char &item : word){
            arr[item - 'a']++;
        }

        //sort array in decreasing order
        sort(arr, arr + 26, greater<int>());

        int count = 0;
        int minPress = 0;

        //assign no
        for(int i = 0; i < 26; i++){
            if(arr[i] == 0)
                break;
                
            int value = arr[i] * ((count / 8) + 1);        //as we will assign values from 2 - 9
            minPress += value;
            count++;
        }
        return minPress;
    }
};