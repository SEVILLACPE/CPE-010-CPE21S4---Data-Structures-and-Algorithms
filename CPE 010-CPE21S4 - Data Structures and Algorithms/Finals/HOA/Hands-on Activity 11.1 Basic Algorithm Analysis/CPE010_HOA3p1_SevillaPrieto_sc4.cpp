#include <iostream>
#include <chrono>
using namespace std;

bool Unique(int A[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] == A[j])
                return false; // duplicate found
    return true; // all unique
}

int main() {
    cout << "n\tTime (microseconds)\tResult\n";
    
    int sizes[] = {100, 500, 1000, 2000};
    for (int n : sizes) {
        int* A = new int[n];
        for (int i = 0; i < n; i++) A[i] = i;
        
        auto start = chrono::high_resolution_clock::now();
        bool result = Unique(A, n);
        auto end = chrono::high_resolution_clock::now();
        
        auto time = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << n << "\t" << time << "\t\t\t" << (result ? "Unique" : "Duplicate") << "\n";
        
        delete[] A;
    }
    return 0;
}