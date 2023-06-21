/*
<aside>
Question 1

Given an array **arr[ ]** of size **N** having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.Next greater element of an element in the array is the nearest element on the right which is greater than the current element.If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

</aside>
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> stack;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stack.empty() && stack.top() < nums2[i]) {
                stack.pop();
            }
            if (stack.empty()) {
                nextGreater[nums2[i]] = -1;
            } else {
                nextGreater[nums2[i]] = stack.top();
            }
            stack.push(nums2[i]);
        }

        vector<int> result;
        for (auto num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
}


/*
<aside>
💡 **Question 2**

Given an array **a** of integers of length **n**, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

**Example 1:**

</aside>
*/

void printPrevSmaller(int arr[], int n)
{
    stack<int> S;
    for (int i=0; i<n; i++)
    {
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
        if (S.empty())
            cout << "_, ";
        else  
            cout << S.top() << ", ";
        S.push(arr[i]);
    }
}

/*
<aside>
💡 **Question 3**

Implement a Stack using two queues **q1** and **q2**.

</aside>
*/

class Stack {
    // Two inbuilt queues
    queue<int> q1, q2;
 
public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }
 
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }
 
    int size() { return q1.size(); }
};


/*
<aside>
💡 **Question 4**

You are given a stack **St**. You have to reverse the stack using recursion.

</aside>
*/

void insert_at_bottom(stack<int>& st, int x)
{
 
    if (st.size() == 0) {
        st.push(x);
    }
    else {
 
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(a);
    }
}
 
void reverse(stack<int>& st)
{
    if (st.size() > 0) {
        int x = st.top();
        st.pop();
        reverse(st);
        insert_at_bottom(st, x);
    }
    return;
}

/*
<aside>
💡 **Question 5**

You are given a string **S**, the task is to reverse the string using stack.

</aside>

*/
void the_helper(string &str){
  stack<char>s;
  for(auto it:str)s.push(it);
  str.clear();
  while(!s.empty()){
    str.push_back(s.top());
    s.pop();
  }
}

/*
<aside>
💡 **Question 6**

Given string **S** representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like ***, /, + and -**.

</aside>
*/

int evaluatePostfix(string exp)
{
    stack<int> st;
    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}


/*
<aside>
💡 **Question 7**

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

</aside>
*/
class MinStack {
public:
    stack<pair<int, int>> s;
    // no, minimum
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }
        else{
            s.push({val, min(s.top().second, val)});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};


/*
<aside>
💡 **Question 8**

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

</aside>
*/

int maxWater(int height[], int n)
{

    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
  
        while ((!st.empty())
               && (height[st.top()] < height[i])) {
            int pop_height = height[st.top()];
            st.pop();
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int min_height
                = min(height[st.top()], height[i])
                  - pop_height;
  
            ans += distance * min_height;
        }
        st.push(i);
    }
    return ans;
}