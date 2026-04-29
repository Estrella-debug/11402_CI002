#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        // 1. Sort the deck in ascending order
        sort(deck.begin(), deck.end());
        
        // 2. Use a queue to simulate the process with indices
        queue<int> indexQueue;
        for (int i = 0; i < n; i++) {
            indexQueue.push(i);
        }
        
        vector<int> result(n);
        // 3. Fill the result based on the simulation rules
        for (int card : deck) {
            // Reveal: The front of the queue is the next spot for a card
            result[indexQueue.front()] = card;
            indexQueue.pop();
            
            // Move: If cards remain, move the next available index to the back
            if (!indexQueue.empty()) {
                indexQueue.push(indexQueue.front());
                indexQueue.pop();
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // 輸入: [17, 13, 11, 2, 3, 5, 7]
    // 預期輸出: [2, 13, 3, 11, 5, 17, 7]
    vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result1 = sol.deckRevealedIncreasing(deck1);

    cout << "Example 1 Result: ";
    for (int card : result1) {
        cout << card << " ";
    }
    cout << endl;

    // 測試範例 2
    // 輸入: [1, 1000]
    // 預期輸出: [1, 1000]
    vector<int> deck2 = {1, 1000};
    vector<int> result2 = sol.deckRevealedIncreasing(deck2);

    cout << "Example 2 Result: ";
    for (int card : result2) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}