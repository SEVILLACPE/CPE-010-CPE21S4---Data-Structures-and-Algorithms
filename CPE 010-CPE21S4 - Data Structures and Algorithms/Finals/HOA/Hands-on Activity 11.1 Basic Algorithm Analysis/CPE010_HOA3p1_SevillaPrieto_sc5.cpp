#include <iostream>
using namespace std;

long long brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    cout << "=== brpower: Logarithmic O(log n) ===\n";
    cout << "x\tn\tResult\t\tSteps ≈ log2(n)\n";
    int x = 2;
    for (int n : {5, 10, 20, 100, 1000}) {
        cout << x << "\t" << n << "\t" << brpower(x, n) << "\t\t" 
             << (31 - __builtin_clz(n)) << "\n";
    }
    return 0;
}