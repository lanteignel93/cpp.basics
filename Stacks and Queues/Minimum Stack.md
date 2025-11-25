---
status: Done
difficulty: Medium
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Minimum Stack
## Description 
Design a stack class that supports the `push`, `pop`, `top`, and `getMin` operations.

- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

Each function should run in O(1) time.

**Example 1:**

```java
Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1
```

**Constraints:**

- `-2^31 <= val <= 2^31 - 1`.
- `pop`, `top` and `getMin` will always be called on **non-empty** stacks.
## Code 
```cpp
class MinStack {
private:
    std::stack<int> _stack; 
    std::stack<int> minStack;  
public:
    MinStack() {
    }
    
    void push(int val) {
        _stack.push(val); 
        if (!minStack.empty()){
            minStack.push(std::min(val, minStack.top())); 
        } else {
            minStack.push(val);
        }
    }
    
    void pop() {
        _stack.pop(); 
        minStack.pop(); 
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```