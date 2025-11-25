---
status: Done
difficulty: Medium
algo: Doubly Linked List
group:
  - Linked List
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Doubly Linked List]]

# Design Linked List
## Description 
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.  
A node in a singly linked list should have two attributes: `val` and `next`. `val` is the value of the current node, and `next` is a pointer/reference to the next node.  
If you want to use the doubly linked list, you will need one more attribute `prev` to indicate the previous node in the linked list. Assume all nodes in the linked list are **0-indexed**.

Implement the `MyLinkedList` class:

- `MyLinkedList()` Initializes the `MyLinkedList` object.
- `int get(int index)` Get the value of the `indexth` node in the linked list. If the index is invalid, return `-1`.
- `void addAtHead(int val)` Add a node of value `val` before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- `void addAtTail(int val)` Append a node of value `val` as the last element of the linked list.
- `void addAtIndex(int index, int val)` Add a node of value `val` before the `indexth` node in the linked list. If `index` equals the length of the linked list, the node will be appended to the end of the linked list. If `index` is greater than the length, the node **will not be inserted**.
- `void deleteAtIndex(int index)` Delete the `indexth` node in the linked list, if the index is valid.

**Example 1:**

**Input**
```
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
```
**Output**
```
[null, null, null, null, 2, null, 3]
```

**Explanation**
```
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```

**Constraints:**

- `0 <= index, val <= 1000`
- Please do not use the built-in LinkedList library.
- At most `2000` calls will be made to `get`, `addAtHead`, `addAtTail`, `addAtIndex` and `deleteAtIndex`.
## Code 
```cpp
struct Node {
    int val; 
    Node *prev; 
    Node *next; 
    Node(int x, Node *p, Node *n) 
        : val(x), prev(p), next(n) {}

    Node(int x = 0) 
        : Node(x, nullptr, nullptr) {}

    Node(int x, Node *n) 
        : Node(x, nullptr, n) {}
};

class MyLinkedList {
private:
    Node head; 
    Node tail; 
    int _length;

public:
    MyLinkedList() {
        head = Node { 0 }; 
        tail = Node { 0 }; 
        head.next = &tail; 
        tail.prev = &head; 
        _length = 0; 
    }

    ~MyLinkedList() {
        Node *curr = head.next;
        while (curr != &tail) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int index) {
        if (index >= _length || index < 0) {
            return -1; 
        }
        Node *curr = head.next;
        for (int i = 0; i < index; i++) {
            curr = curr->next; 
        } 
        return curr->val; 
    }
    
    void addAtHead(int val) {
        Node *newNode = new  Node(val); 
        Node *next = head.next; 
        newNode->prev = &head; 
        head.next = newNode; 
        newNode->next = next; 
        next->prev = newNode; 
        _length++;
        return; 
    }
    
    void addAtTail(int val) {
        Node *newNode = new  Node(val); 
        Node *prev = tail.prev; 
        newNode->next = &tail; 
        tail.prev = newNode;
        newNode->prev = prev;
        prev->next = newNode; 
        _length++;  
        return; 
    }
    
    void addAtIndex(int index, int val) {
        if (index == _length) {
            addAtTail(val); 
            return; 
        }
        if (index == 0) {
            addAtHead(val); 
            return; 
        }
        if (index < 0  || index > _length) {
            return; 
        }
        Node *curr = &head;
        for (int i = 0; i < index; i++) {
            curr = curr->next; 
        }
        Node *newNode = new  Node(val); 
        Node *next = curr->next;
        next->prev = newNode; 
        curr->next = newNode; 
        newNode->next = next; 
        newNode->prev = curr; 
        _length++; 
        return;  
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _length) {
            return;  
        }
        Node *curr = &head; 
        for (int i = 0; i < index; i++) {
            curr = curr->next; 
        }
        Node *nodeToDelete = curr->next;
        Node *nextNode = nodeToDelete->next;
        
        curr->next = nextNode; 
        nextNode->prev = curr; 
        delete nodeToDelete; 

        _length--;  
    }
};

```

