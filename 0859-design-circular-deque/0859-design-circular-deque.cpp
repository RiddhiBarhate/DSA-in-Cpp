class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;
    int count;

    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = 0;
        rear = size - 1;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        else{
            front = (front - 1 + size) % size;
            arr[front] = value;
            count++;
            return true;
        }
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        else{ 
            rear = (rear + 1) % size;
            arr[rear] = value;
            count++;
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        else{
            front = (front + 1) % size;
            count--;
            return true;
        }
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        else{
            rear = (rear - 1 + size) % size;
            count--;
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        else
            return arr[rear];
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */