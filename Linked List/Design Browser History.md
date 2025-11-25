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

# Design Browser History
## Description 
You have a **browser** of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

Implement the `BrowserHistory` class:

- `BrowserHistory(string homepage)` Initializes the object with the `homepage` of the browser.
- `void visit(string url)` Visits `url` from the current page. It clears up all the forward history.
- `string back(int steps)` Move `steps` back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current `url` after moving back in history **at most** `steps`.
- `string forward(int steps)` Move `steps` forward in history. If you can only forward `x` steps in the history and `steps > x`, you will forward only `x` steps. Return the current `url` after forwarding in history **at most** `steps`.

**Example:**

**Input:**
```
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
```
**Output:**
```
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
```

**Explanation:**
```
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"

```
**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of  '.' or lower case English letters.
- At most `5000` calls will be made to `visit`, `back`, and `forward`.
## Code 
```cpp
struct WebNode {
    std::string url; 
    WebNode *prev; 
    WebNode *next; 
    WebNode(std::string x, WebNode *p, WebNode *n) 
        : url(x), prev(p), next(n) {}

    WebNode(std::string x = "") 
        : WebNode(x, nullptr, nullptr) {}

    WebNode(std::string x, WebNode *n) 
        : WebNode(x, nullptr, n) {}
};

class BrowserHistory {
private: 
    WebNode *head = new WebNode(""); 
    WebNode *tail = new WebNode(""); 
    WebNode *curr = nullptr; 
    int _length = 0;  

public:
    BrowserHistory(string homepage) {
        _length++; 
        WebNode *page = new WebNode(homepage); 
        head->next = page; 
        tail->prev = page; 
        page->prev = head; 
        page->next = tail; 
        curr = page; 
    }
    
    void visit(string url) {
        WebNode *newPage = new WebNode(url);
        WebNode *oldFuture = curr->next; 
        // Clear memory of old pointers 
        while (oldFuture != tail && oldFuture != nullptr) {
            WebNode *old = oldFuture; 
            oldFuture = oldFuture->next; 
            _length--; 
            delete old; 
        } 
        curr->next = newPage; 
        newPage->next = tail; 
        tail->prev = newPage; 
        newPage->prev = curr; 
        curr = curr->next; 
        _length++; 
    }
    
    string back(int steps) {
        while (curr->prev != head && steps > 0) {
            curr = curr->prev; 
            steps--; 
        }
        return curr->url; 
    }
    
    string forward(int steps) {
        while (curr->next != tail && steps > 0) {
            curr = curr->next; 
            steps--; 
        }
        return curr->url; 
    }
};

```

