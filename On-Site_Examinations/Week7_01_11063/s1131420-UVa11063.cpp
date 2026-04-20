#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, test_case = 1;
    while (cin >> n){
        bool is_B2 = true;
        vector <int> num(n);
        for (int i = 0; i < n; ++i){
            cin >> num[i];
            if (num[i] < 1){
                is_B2 = false;
            }
        }
        bool is_strictly_increasing = is_B2;
        for (int i = 1; i < n; ++i){
            if (num[i] <= num[i - 1]){
                is_strictly_increasing = false;
                break;
            }
        }
        is_B2 = is_strictly_increasing;
        set <int> sums;
        if (is_B2){
            for (int i = 0; i < n; ++i){
                for (int j = i; j < n; ++j){
                    int sum = num[i] + num[j];
                    if (sums.count(sum) > 0){
                        is_B2 = false;
                        break;
                    }
                    sums.insert(sum);
                }
                if (!is_B2) break;
            }
        }
        cout << "Case #" << test_case++ << ": " << (is_B2 ? "It is a B2-Sequence." : "It is not a B2-Sequence.") << "\n" << "\n";
    }
    return 0;
}
