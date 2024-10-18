class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        typedef pair<int, char> P;
        priority_queue<P, vector<P>> pq;

        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});

        string result = "";

        while(!pq.empty()){
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length() - 1] == currChar
                && result[result.length() - 2] == currChar){
                    //we cannot push the same char, search for next char

                    if(pq.empty())
                        break;

                    int nextCount = pq.top().first;
                    char nextChar = pq.top().second;
                    pq.pop();

                    result.push_back(nextChar);
                    nextCount--;

                    if(nextCount > 0)
                        pq.push({nextCount, nextChar});
                }
                else{
                    result.push_back(currChar);
                    currCount--;
                }

                if(currCount > 0)
                    pq.push({currCount, currChar});
        }

        return result;
    }
};