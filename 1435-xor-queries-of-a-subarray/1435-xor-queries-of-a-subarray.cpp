class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cummXOR(n, 0);
        cummXOR[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            cummXOR[i] = cummXOR[i - 1] ^ arr[i];
        }

        vector<int> result;
        for(vector<int>& query : queries){
            int left = query[0];
            int right = query[1];

            int XOR = cummXOR[right] ^ (left == 0 ? 0 : cummXOR[left - 1]);
            result.push_back(XOR);
        }

        return result;
    }
};