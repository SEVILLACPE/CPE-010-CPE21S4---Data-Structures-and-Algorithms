#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>>& mat, int m, int n, int cost) {
    if (cost < 0) return 0;
    if (m == 0 && n == 0) return (mat[0][0] == cost) ? 1 : 0;
    if (m == 0) return countPaths(mat, 0, n - 1, cost - mat[m][n]);
    if (n == 0) return countPaths(mat, m - 1, 0, cost - mat[m][n]);
    
    return countPaths(mat, m - 1, n, cost - mat[m][n]) +
           countPaths(mat, m, n - 1, cost - mat[m][n]);
}

int main() {
    vector<vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 7, 3, 4}
    };
    int targetCost = 25;
    int M = matrix.size(), N = matrix[0].size();
    
    cout << "Matrix:\n";
    for (auto &row : matrix) {
        for (int v : row) cout << v << " ";
        cout << "\n";
    }
    cout << "\nTarget Cost: " << targetCost << "\n";
    cout << "Number of paths: " << countPaths(matrix, M - 1, N - 1, targetCost) << "\n";
    return 0;
}