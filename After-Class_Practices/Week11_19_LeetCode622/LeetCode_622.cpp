#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    // 初始化佇列，設定大小為 k
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = 0;
        capacity = k;
    }
    
    // 向佇列插入一個元素
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) head = 0;
        // 使用取餘數來達成迴圈效果
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
        return true;
    }
    
    // 從佇列刪除一個元素
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) {
            // 如果只有一個元素，刪除後重置指標
            head = -1;
            tail = -1;
        } else {
            // head 順著迴圈往後移動
            head = (head + 1) % capacity;
        }
        size--;
        return true;
    }
    
    // 取得隊首元素
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    
    // 取得隊尾元素
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    
    // 檢查佇列是否為空
    bool isEmpty() {
        return size == 0;
    }
    
    // 檢查佇列是否已滿
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    // 建立大小為 3 的迴圈佇列
    MyCircularQueue myCircularQueue(3);

    cout << boolalpha; // 讓 bool 值顯示為 true/false
    
    // 測試入隊
    cout << "EnQueue 1: " << myCircularQueue.enQueue(1) << endl; // true
    cout << "EnQueue 2: " << myCircularQueue.enQueue(2) << endl; // true
    cout << "EnQueue 3: " << myCircularQueue.enQueue(3) << endl; // true
    cout << "EnQueue 4 (Full): " << myCircularQueue.enQueue(4) << endl; // false (滿了)

    // 檢查狀態
    cout << "Rear element: " << myCircularQueue.Rear() << endl;  // 3
    cout << "Is full: " << myCircularQueue.isFull() << endl;     // true

    // 測試出隊
    cout << "DeQueue: " << myCircularQueue.deQueue() << endl;    // true
    cout << "EnQueue 4: " << myCircularQueue.enQueue(4) << endl; // true (之前刪了一個，現在可以加進去)
    
    cout << "Rear element: " << myCircularQueue.Rear() << endl;  // 4
    cout << "Front element: " << myCircularQueue.Front() << endl; // 2 (1 被刪了)

    return 0;
}