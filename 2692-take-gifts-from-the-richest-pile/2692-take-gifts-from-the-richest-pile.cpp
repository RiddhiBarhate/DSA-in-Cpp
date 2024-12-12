class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        for(int i = 0; i < k; i++){
            int maxEle = pq.top();
            pq.pop();

            int newEle = maxEle - floor(sqrt(maxEle));
            pq.push(maxEle - newEle);
        }

        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};