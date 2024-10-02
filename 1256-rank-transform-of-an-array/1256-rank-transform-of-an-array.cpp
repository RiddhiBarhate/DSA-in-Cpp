class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> result = arr;
        sort(result.begin(), result.end());
        unordered_map<int, int> mp;

        int i = 0, rank = 1;
        while(i < arr.size()){
            if(i == 0){}
            else if(result[i] == result[i-1]){}
            else
                rank++;

            mp[result[i]] = rank;
            i++;
        }

        for(auto &x : arr){
            x = mp[x];
        }

        return arr;
    }
};