#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinStepsBottomUp(int n) {
    vector<int> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0)
            dp[i] = min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}

int main() {
    int testValues[] = {1, 4, 7, 10, 15, 20};
    for (int n : testValues)
        cout << n << "\t" << getMinStepsBottomUp(n) << endl;
    return 0;
}