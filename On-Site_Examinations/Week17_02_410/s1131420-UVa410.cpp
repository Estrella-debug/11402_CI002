#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main() {
    int C, S, n, TC=0;
    double sum, avg, imbalance;
    while (cin >> C >> S) {
        n = 2 * C;
        int a[20] = {0};
        sum = 0.0;
        for (int i=0; i<S; i++) {
            cin >> a[i];
            sum += a[i];
        }
        avg = sum / C;
        sort(a, a+n);
        imbalance = 0.0;
        printf("Set #%d\n", ++TC);
        for (int i=0; i<C; i++) {
            printf("%2d:", i);
            if (a[i])
                printf(" %d", a[i]);
            if (a[n-1-i])
                printf(" %d", a[n-1-i]);
            imbalance += abs(a[i] + a[n-1-i] - avg);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n", imbalance);
        if (TC) printf("\n");
    }
    return 0;
}