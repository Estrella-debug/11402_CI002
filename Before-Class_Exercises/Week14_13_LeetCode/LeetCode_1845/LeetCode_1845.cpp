#include <queue>
#include <vector>

using namespace std;

class SeatManager {
private:
    // Min-heap to store available seat numbers
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    // O(N log N) to initialize the heap with all seats
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            availableSeats.push(i);
        }
    }
    
    // O(log N) to fetch and remove the smallest unreserved seat
    int reserve() {
        int seat = availableSeats.top();
        availableSeats.pop();
        return seat;
    }
    
    // O(log N) to add the seat back to the available pool
    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};
