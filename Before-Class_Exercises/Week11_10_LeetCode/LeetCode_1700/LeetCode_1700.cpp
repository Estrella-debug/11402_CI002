#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        int count = 0;

        // 將學生放入佇列 (Queue)，維持排隊順序
        for (int i : students) {
            q.push(i);
        }
        // 將三明治放入堆疊 (Stack)，注意要反向放入才能讓第一個在最上面
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            s.push(sandwiches[i]);
        }

        // 當 count 超過佇列長度時，代表剩下的學生都不喜歡最上面的三明治
        while (count < q.size()) {
            if (s.empty() || q.empty()) {
                break;
            }
            
            if (q.front() == s.top()) {
                // 學生喜歡這個三明治：拿走並離開隊伍
                s.pop();
                q.pop();
                count = 0; // 重置計數器
            } else {
                // 學生不喜歡：排到隊伍最後面
                q.push(q.front());
                q.pop();
                count++; // 記錄連續不喜歡的人數
            }
        }
        
        return q.size();
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // 學生: [1,1,0,0], 三明治: [0,1,0,1]
    // 預期輸出: 0 (所有人都能吃到)
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << "Example 1 Result: " << sol.countStudents(students1, sandwiches1) << endl;

    // 測試範例 2
    // 學生: [1,1,1,0,0,1], 三明治: [1,0,0,0,1,1]
    // 預期輸出: 3
    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << "Example 2 Result: " << sol.countStudents(students2, sandwiches2) << endl;

    return 0;
}