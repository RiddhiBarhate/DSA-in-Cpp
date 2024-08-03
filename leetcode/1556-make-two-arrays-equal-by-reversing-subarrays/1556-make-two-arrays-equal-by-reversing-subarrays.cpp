class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        int i = 0;
        int count = 0;
        while(i < target.size()){
            if(target[i] == arr[i]){
                count++;
            }
            i++;
        }
        if(count == target.size()){
            return true;
        }
        else{
            return false;
        }
    }
};