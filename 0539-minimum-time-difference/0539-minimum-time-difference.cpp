class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        for(int i = 0; i < n; i++){
            string time = timePoints[i];

            string hoursubstr = time.substr(0, 2);   //hh
            string minsubstr = time.substr(3);   //mm

            int hourINT = stoi(hoursubstr);
            int minINT = stoi(minsubstr);

            minutes[i] = hourINT * 60 + minINT;     //remove minutes with reference to 00:00
        }

        sort(minutes.begin(), minutes.end());

        int result = INT_MAX;
        for(int i = 1; i < n; i++){
            result = min(result, minutes[i] - minutes[i - 1]);
        }

        return min(result, (24 * 60 - minutes[n - 1] + minutes[0]));   //anticlockwise difference between two closet points to 00:00
    }
};