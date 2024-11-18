class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if(k == 0)
            return result;

        int i = -1, j = -1;
        if(k > 0){
            i = 1;
            j = k;
        }
        else{
            i = n - abs(k);
            j = n - 1;
        }

        int WindowSum = 0;
        for(int pointer = i; pointer <= j; pointer++){
            WindowSum += code[pointer];
        }

        for(int k = 0; k < n; k++){
            result[k] = WindowSum;

            WindowSum -= code[i % n];
            i++;

            WindowSum += code[(j + 1) % n];
            j++;
        }

        return result;
    }
};