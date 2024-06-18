#include <stack>
class SpecialStack {
    //Here we are pushing and poping two elements 
    //one is data and another is minimum value
    public:
    stack<int> s;
    void push(int data) {
        if(s.empty())
        {
            s.push(data);
            s.push(data);
        }else
        {
            if(data<s.top())
            {
                s.push(data);
                s.push(data);
            }else
            {
                int mini=s.top();
                s.push(data);
                s.push(mini);
            }
        }
    }

    void pop() {
        if(s.empty())
        return;

        s.pop();
        s.pop();
    }

    int top() {
        if(s.empty())
        return -1;

        int temp1=s.top();
        s.pop();
        int temp2=s.top();
        s.push(temp1);

        return temp2;
    }

    int getMin() {
        if(s.empty())
        return -1;

        return s.top();
    }  
};