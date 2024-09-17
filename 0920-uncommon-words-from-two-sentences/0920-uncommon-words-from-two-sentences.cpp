class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;
        string word = "";

        stringstream ss1(s1);
        while(ss1 >> word){
            words[word]++;
        }

        stringstream ss2(s2);
        while(ss2 >> word){
            words[word]++;
        }

        vector<string> ans;

        for(auto w : words){
            if(w.second == 1)
                ans.push_back(w.first);
        }

        return ans;
    }
};