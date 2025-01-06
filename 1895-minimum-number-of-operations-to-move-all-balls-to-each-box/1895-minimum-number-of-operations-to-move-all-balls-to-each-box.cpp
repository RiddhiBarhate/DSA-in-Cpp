class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> index;

        for(int i = 0; i < n; i++){
            if(boxes[i] == '1'){
                index.push_back(i);
            }
        }

        int m = index.size();
        int sum = 0, i = 0;
        vector<int> result(n, 0);
        
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < m; j++){
                sum += abs(index[j] - i);
            }
            result[i] = sum;
        }

        return result;
    }
};