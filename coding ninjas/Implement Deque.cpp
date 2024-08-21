#include <bits/stdc++.h> 

class Deque
{
    int *arr;
    int size;
    int front;
    int rear;
    int count;

public:

    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(count == size){
            return false;
        }

        if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = x;
        count++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(count == size){
            return false;
        }

        if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size - 1){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        count++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(count == 0){
            return -1;
        }
        
        int ans = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        count--;
        return ans;
        
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(count == 0){
            return -1;
        }

        int ans = arr[rear];
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size - 1;
        }
        else{
            rear--;
        }
        count--;
        return ans;
        
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(count == 0){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(count == 0){
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(count == 0){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(count == size){
            return true;
        }
        else{
            return false;
        }
    }
};