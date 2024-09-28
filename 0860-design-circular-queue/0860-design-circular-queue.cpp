class MyCircularQueue {
public:

    int *arr;
    int size;
    int front;
    int rear;
    int count;

    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        else{
            arr[rear] = value;
            rear = (rear + 1) % size;
            count++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else{
            front = (front + 1) % size;
            count--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        else
            return arr[(rear - 1 + size) % size];  // Access the element just before the current rear position
    }
    
    bool isEmpty() {
        if(count == 0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(count == size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */