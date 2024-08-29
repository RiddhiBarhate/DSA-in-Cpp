class Solution {
public:

    long halfToPalindrome(long left, bool even) {
        long resultNum = left;
        if (!even) {
            left = left / 10;
        }

        while (left > 0) {
            int digit = left % 10;
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }
        return resultNum;
    }

    string nearestPalindromic(string n) {

       int len = n.length();
       int mid = len / 2;
       long firstHalfStr = stol(n.substr(0, len%2 == 0 ? mid : mid + 1));
    
       vector<long> possibleWays;
       possibleWays.push_back(halfToPalindrome(firstHalfStr, len%2 == 0));
       possibleWays.push_back(halfToPalindrome(firstHalfStr + 1, len%2 == 0));
       possibleWays.push_back(halfToPalindrome(firstHalfStr - 1, len%2 == 0));
       possibleWays.push_back((long)pow(10, len - 1) - 1);
       possibleWays.push_back((long)pow(10, len) + 1);

       long diff         = LONG_MAX;
       long result       = 0;
       long originalNum  = stol(n);

        for (long &num : possibleWays) {
            if (num == originalNum) continue;
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                result = num;
            } else if (abs(num - originalNum) == diff) {
                result = min(result, num);
            }
        }

        return to_string(result);

    }
};