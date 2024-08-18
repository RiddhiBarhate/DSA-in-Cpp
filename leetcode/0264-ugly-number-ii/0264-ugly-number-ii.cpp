class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        arr[1] = 1;

        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        for(int i = 2; i <= n; i++){
            int i2UglyNo = arr[i2] * 2;
            int i3UglyNo = arr[i3] * 3;
            int i5UglyNo = arr[i5] * 5;

            int minUglyNo = min({i2UglyNo, i3UglyNo, i5UglyNo});

            arr[i] = minUglyNo;

            if(minUglyNo == i2UglyNo)
                i2++;
            if(minUglyNo == i3UglyNo)
                i3++;
            if(minUglyNo == i5UglyNo)
                i5++;
        }

        return arr[n];
    }
};