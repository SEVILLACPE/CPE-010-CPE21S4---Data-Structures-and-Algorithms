#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

bool Unique(int A[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] == A[j])
                return false;
    return true;
}

bool Unique_Fast(int A[], int n) {
    sort(A, A + n);
    for (int i = 1; i < n; i++)
        if (A[i] == A[i-1])
            return false;
    return true;
}

int main() {
    int sizes[] = {100, 500, 1000, 2000};
    for (int n : sizes) {
        int* A = new int[n];
        for (int i = 0; i < n; i++) A[i] = i;

        auto t0 = chrono::high_resolution_clock::now();
        bool r1 = Unique(A, n);
        auto t1 = chrono::high_resolution_clock::now();
        bool r2 = Unique_Fast(A, n);
        auto t2 = chrono::high_resolution_clock::now();

        auto t_n2 = chrono::duration<double,micro>(t1-t0).count();
        auto t_nlogn = chrono::duration<double,micro>(t2-t1).count();
        cout << "n=" << n << " | O(n²): " << t_n2 << " µs | O(n log n): " << t_nlogn << " µs\n";
        delete[] A;
    }
    return 0;
}