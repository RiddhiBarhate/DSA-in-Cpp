class CustomStack {
public:

    int *arr;
    int size;
    int top;
    int count;

    CustomStack(int maxSize) {
        size = maxSize;
        arr = new int[size];
        top = 0;
        count = 0;
    }
    
    void push(int x) {
        if(count < size){
            arr[top] = x;
            top++;
            count++;
        }
    }
    
    int pop() {
        if(count == 0)
            return -1;
        else{
            top--;
            int ans = arr[top];
            count--;
            return ans;
        }
    }
    
    void increment(int k, int val) {
        if(k > size){
            for(int i = 0; i < size; i++){
                arr[i] += val;
            }
        }
        else{
            for(int i = 0; i < k; i++){
                arr[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */