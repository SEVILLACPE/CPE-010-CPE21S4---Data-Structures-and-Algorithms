#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int partitionEndPivot(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortEndPivot(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionEndPivot(arr, low, high);
        quickSortEndPivot(arr, low, pi - 1);
        quickSortEndPivot(arr, pi + 1, high);
    }
}

int partitionMiddlePivot(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[mid], arr[high]);
    return partitionEndPivot(arr, low, high);
}

void quickSortMiddlePivot(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionMiddlePivot(arr, low, high);
        quickSortMiddlePivot(arr, low, pi - 1);
        quickSortMiddlePivot(arr, pi + 1, high);
    }
}

int main() {
    vector<int> sizes = {100, 1000, 10000};
    for (int n : sizes) {
        vector<int> sortedData(n);
        iota(sortedData.begin(), sortedData.end(), 1);

        vector<int> reverseData(n);
        for (int i = 0; i < n; ++i) reverseData[i] = n - i;

        vector<int> temp = reverseData;
        auto start = high_resolution_clock::now();
        quickSortMiddlePivot(temp, 0, temp.size() - 1);
        auto end = high_resolution_clock::now();
        double bestTime = duration<double, milli>(end - start).count();

        temp = sortedData;
        start = high_resolution_clock::now();
        quickSortEndPivot(temp, 0, temp.size() - 1);
        end = high_resolution_clock::now();
        double worstTime = duration<double, milli>(end - start).count();

        cout << "Input Size N = " << n << ":\n";
        cout << "  Best Case Time:  " << bestTime << " ms\n";
        cout << "  Worst Case Time: " << worstTime << " ms\n\n";
    }

    return 0;
}