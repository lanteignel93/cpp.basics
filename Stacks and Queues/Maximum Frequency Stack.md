---
status: Done
difficulty: Hard
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Maximum Frequency Stack 
## Description 
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:

- `FreqStack()` constructs an empty frequency stack.
- `void push(int val)` pushes an integer `val` onto the top of the stack.
- `int pop()` removes and returns the most frequent element in the stack.
    - If there is a **tie** for the **most frequent element**, the element closest to the stack's top is removed and returned.

**Example 1:**

```java
Input: ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

Output: [null, null, null, null, null, null, null, 5, 7, 5, 4]
```

Explanation:  
```
FreqStack freqStack = new FreqStack();  
freqStack.push(5); // The stack is [5]  
freqStack.push(7); // The stack is [5,7]  
freqStack.push(5); // The stack is [5,7,5]  
freqStack.push(7); // The stack is [5,7,5,7]  
freqStack.push(4); // The stack is [5,7,5,7,4]  
freqStack.push(5); // The stack is [5,7,5,7,4,5]  
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].  
freqStack.pop(); // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].  
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,4].  
freqStack.pop(); // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```


**Constraints:**

- `0 <= val <= 1,000,000,000`
- At most `20,000` calls will be made to `push` and `pop`.
- It is guaranteed that there will be at least one element in the stack before calling `pop`.
## Code 
```cpp
class FreqStack {
public:
    std::unordered_map<int, int> cnt; 
    std::unordered_map<int, std::stack<int>> stacks; 
    int maxCnt { 0 };  

    FreqStack() {

    }
    
    void push(int val) {
        int valCnt = ++cnt[val]; 
        if (valCnt > maxCnt) {
            maxCnt = valCnt; 
            stacks[valCnt] = stack<int>(); 
        }
        stacks[valCnt].push(val);      
    }
    
    int pop() {
        int res = stacks[maxCnt].top(); 
        stacks[maxCnt].pop(); 
        cnt[res]--; 
        if (stacks[maxCnt].empty()){
            maxCnt--; 
        }
        return res; 
    }
};

```