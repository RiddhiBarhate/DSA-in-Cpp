#include <bits/stdc++.h>

void solve(stack<int> &s, int num){
	if(s.empty() || s.top() < num){
		s.push(num);
		return;
	}

	int n = s.top();
	s.pop();

	solve(s, num);
	s.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return;

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	solve(stack, num);
}