#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int n, s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;  //no of stacks
        s = S;  //size of array
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //initialize top with -1
        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        //initialize next with 1,2,3....
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }

        //initialize freespot
        freespot = 0;

        //initialize last element of next with -1
        next[s-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {   
        //check overflow
        if(freespot == -1)
            return false;

        //initialize index
        int index = freespot;

        //push element
        arr[index] = x;

        //update freespot
        freespot = next[index];

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow
        if(top[m-1] == -1)
            return -1;

        //for pop reverse everything done in push
        
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};