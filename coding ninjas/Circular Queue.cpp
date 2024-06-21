#include <bits/stdc++.h> 
class CircularQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;
        int count;

    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(count == size){
            return false;
        }
        else{
            arr[rear] = value;
            rear = (rear+1) % size;   //to maintain cycle
            count++;
            return true; 
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(count == 0){
            return -1;
        }
        else{
            int ans = arr[front];
            front = (front+1) % size;
            count--;
            return ans;
        }
    }
};