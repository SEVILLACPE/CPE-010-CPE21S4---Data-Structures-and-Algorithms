#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> memo;

int getMinStepsMemo(int n) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];
    
    int r = 1 + getMinStepsMemo(n - 1);
    if (n % 2 == 0)
        r = min(r, 1 + getMinStepsMemo(n / 2));
    if (n % 3 == 0)
        r = min(r, 1 + getMinStepsMemo(n / 3));
    
    memo[n] = r;
    return r;
}

int main() {
    int testValues[] = {1, 4, 7, 10, 15, 20};
    for (int n : testValues) {
        memo.assign(n + 1, -1);
        cout << n << "\t" << getMinStepsMemo(n) << endl;
    }
    return 0;
}