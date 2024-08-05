class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        for(string item : arr)    //stores the count of items
            countMap[item]++;

        int count = 0;
        for(string item : arr){
            if(countMap[item] == 1){        //as count is 1, item is distinct
                count++; 

                if(count == k)
                    return item;
            }   
        }
        return "";
    }
};