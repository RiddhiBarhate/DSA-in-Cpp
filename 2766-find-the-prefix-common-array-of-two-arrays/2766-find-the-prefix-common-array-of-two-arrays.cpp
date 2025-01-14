class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                for(int k = 0; k <= i; k++){
                    if(A[j] == B[k])
                        count++;
                }
            }
            arr[i] = count;
            count = 0;
        }

        return arr;
    }
};