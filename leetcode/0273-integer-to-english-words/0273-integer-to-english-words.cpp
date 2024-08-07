class Solution {
public:
    string numberToWords(int num) {
        string belowten[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string belowtwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string belowhundred[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        if(num == 0)
            return "Zero";
        else if(num < 10)
            return belowten[num];
        else if(num < 20)
            return belowtwenty[num - 10];
        else if(num < 100)
            return belowhundred[num/10] + (num%10 != 0 ? " " + belowten[num%10] : "");
        else if(num < 1000)
            return belowten[num/100] + " Hundred" + (num%100 != 0 ? " " + numberToWords(num%100) : "");
        else if(num < 1000000)
            return numberToWords(num/1000) + " Thousand" + (num%1000 != 0 ? " " + numberToWords(num%1000) : "");
        else if(num < 1000000000)
            return numberToWords(num/1000000) + " Million" + (num%1000000 != 0 ? " " + numberToWords(num%1000000) : "");
        else
            return numberToWords(num/1000000000) + " Billion" + (num%1000000000 != 0 ? " " + numberToWords(num%1000000000) : "");
    }
};