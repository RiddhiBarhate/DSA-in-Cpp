#include <bits/stdc++.h>

char tolowercase(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else{
        char temp= ch-'A'+'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    // Write your code here.
    int start=0;
    int end=s.size()-1;
    while(start<=end)
    {
        if(!isalnum(s[start]))
        {
            start++;
        }
        else if(!isalnum(s[end]))
        {
            end--;
        }
        else if(tolowercase(s[start])!=tolowercase(s[end]))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}