void solve(stack<int> &stack, int element){
    
    if (stack.empty()) {
        stack.push(element);
        return;
    }

    int topElement = stack.top();
    stack.pop();

    solve(stack, element);
    stack.push(topElement);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty()) {
        return;
    }

    int topElement = stack.top();
    stack.pop();
    reverseStack(stack);
    solve(stack, topElement);
    return;
}