#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyQueue {
public:
    stack<int> s; // 堆疊頂端始終維持是最早進入的元素 (舊的在前)

    MyQueue() {}

    // 每次推入新元素，都透過暫存堆疊將新元素放到最底層
    void push(int x) {
        stack<int> t;
        // 把現有的全部搬走
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        // 放入新元素到空堆疊底部
        s.push(x);
        // 把原本的元素搬回來放在新元素上面
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }

    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }

    int peek() { 
        return s.top(); 
    }

    bool empty() { 
        return s.empty(); 
    }
};

int main() {
    MyQueue myQueue;

    // 測試 push 操作
    cout << "Pushing 1, 2, 3 into queue..." << endl;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // 測試 peek (預期應為 1，因為 1 最早進入)
    cout << "Queue peek: " << myQueue.peek() << " (Expected: 1)" << endl;

    // 測試 pop (預期應彈出 1)
    cout << "Queue pop: " << myQueue.pop() << " (Expected: 1)" << endl;

    // 再次檢查 peek (預期應變為 2)
    cout << "New queue peek: " << myQueue.peek() << " (Expected: 2)" << endl;

    // 檢查 empty
    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << " (Expected: No)" << endl;

    // 清空佇列
    myQueue.pop(); // 彈出 2
    myQueue.pop(); // 彈出 3
    cout << "After popping all, is queue empty? " << (myQueue.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl;

    return 0;
}