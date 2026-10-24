#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> sizes = {100, 1000, 10000};

    cout << fixed << setprecision(4);
    for (int n : sizes) {
        vector<int> sortedData(n);
        iota(sortedData.begin(), sortedData.end(), 1);

        vector<int> reverseData(n);
        for (int i = 0; i < n; ++i) reverseData[i] = n - i;

        vector<int> temp = sortedData;
        auto start = high_resolution_clock::now();
        mergeSort(temp, 0, temp.size() - 1);
        auto end = high_resolution_clock::now();
        double bestTime = duration<double, milli>(end - start).count();

        temp = reverseData;
        start = high_resolution_clock::now();
        mergeSort(temp, 0, temp.size() - 1);
        end = high_resolution_clock::now();
        double worstTime = duration<double, milli>(end - start).count();

        cout << "Input Size N = " << n << ":\n";
        cout << "  Best Case Time:  " << bestTime << " ms\n";
        cout << "  Worst Case Time: " << worstTime << " ms\n\n";
    }

    return 0;
}