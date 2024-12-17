class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();
        vector<int> count(26, 0);
        for(char &ch : s){
            count[ch - 'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                pq.push('a' + i);
            }
        }

        string result = "";
        while(!pq.empty()){
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch - 'a'], repeatLimit);
            result.append(freq, ch);

            count[ch - 'a'] -= freq;

            if(count[ch - 'a'] > 0 && !pq.empty()){
                char nextCh = pq.top();
                pq.pop();

                result.push_back(nextCh);
                count[nextCh - 'a']--;

                if(count[nextCh - 'a'] > 0){
                    pq.push(nextCh);
                }

                pq.push(ch);
            }
        }
        return result;
    }
};