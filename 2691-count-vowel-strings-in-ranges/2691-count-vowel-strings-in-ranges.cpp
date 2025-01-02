class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> cumSum(n);
        int count = 0, i = 0;

        for(string& word : words){
            int l = word.length() - 1;
            if((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') &&
                (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')){
                    count++;
            }  
            cumSum[i] = count;
            i++; 
        }

        vector<int> result(m, 0);
        i = 0;
        for(vector<int>& query : queries){
            int l = query[0];
            int r = query[1];

            if(l == 0){
                result[i] = cumSum[r];
            }
            else{
                result[i] = cumSum[r] - cumSum[l-1];
            }

            i++;
        }
        return result;
    }
};