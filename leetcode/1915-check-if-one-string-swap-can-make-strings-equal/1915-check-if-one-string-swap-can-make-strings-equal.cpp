class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int> idx;

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                idx.push_back(i);
            }
        }

        int size = idx.size();
        if(idx.size() != 0 && idx.size() != 2)
                return false;
        
        if(size == 2)
            swap(s2[idx[0]], s2[idx[1]]);

        return s1 == s2;
    }
};