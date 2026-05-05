#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> buffer;
    int head;
    int tail;
    int capacity;
    int size;

public:
    // 初始化雙端佇列，設定大小為 k
    MyCircularDeque(int k) : buffer(k), head(0), tail(k - 1), capacity(k), size(0) {}
    
    // 在隊首插入元素
    bool insertFront(int value) {
        if (isFull()) return false;
        // 逆向移動 head
        head = (head - 1 + capacity) % capacity;
        buffer[head] = value;
        size++;
        return true;
    }
    
    // 在隊尾插入元素
    bool insertLast(int value) {
        if (isFull()) return false;
        // 順向移動 tail
        tail = (tail + 1) % capacity;
        buffer[tail] = value;
        size++;
        return true;
    }
    
    // 從隊首刪除元素
    bool deleteFront() {
        if (isEmpty()) return false;
        // 順向移動 head 視為刪除
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    // 從隊尾刪除元素
    bool deleteLast() {
        if (isEmpty()) return false;
        // 逆向移動 tail 視為刪除
        tail = (tail - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    // 取得隊首元素
    int getFront() {
        return isEmpty() ? -1 : buffer[head];
    }
    
    // 取得隊尾元素
    int getRear() {
        return isEmpty() ? -1 : buffer[tail];
    }
    
    // 檢查是否為空
    bool isEmpty() {
        return size == 0;
    }
    
    // 檢查是否已滿
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    // 建立一個容量為 3 的雙端佇列
    MyCircularDeque deque(3);

    cout << boolalpha; // 讓布林值印出 true/false

    // 測試各種操作
    cout << "Insert Last 1: " << deque.insertLast(1) << endl;   // true
    cout << "Insert Last 2: " << deque.insertLast(2) << endl;   // true
    cout << "Insert Front 3: " << deque.insertFront(3) << endl; // true
    cout << "Insert Front 4 (Full): " << deque.insertFront(4) << endl; // false

    cout << "Rear element: " << deque.getRear() << endl;   // 2
    cout << "Front element: " << deque.getFront() << endl; // 3

    cout << "Is full: " << deque.isFull() << endl; // true

    cout << "Delete Last: " << deque.deleteLast() << endl;   // true
    cout << "Insert Last 4: " << deque.insertLast(4) << endl; // true

    cout << "New Rear: " << deque.getRear() << endl; // 4

    return 0;
}