#include <iostream>
using namespace std;

long long rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

int main() {
    int x = 2;
    int exp[] = {10, 20, 50, 100};
    for (int n : exp)
        cout << x << "^" << n << " = " << rpower(x, n)
             << " | Steps = " << n << " → O(n)\n";
    return 0;
}