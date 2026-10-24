#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = 0; i < k; ++i) {
        arr[left + i] = temp[i];
    }
}

void sequentialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    sequentialMergeSort(arr, left, mid);
    sequentialMergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth = 0) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    if (depth < 2) {
        std::thread leftThread(parallelMergeSort, std::ref(arr), left, mid, depth + 1);
        parallelMergeSort(arr, mid + 1, right, depth + 1);
        leftThread.join();
    } else {
        sequentialMergeSort(arr, left, mid);
        sequentialMergeSort(arr, mid + 1, right);
    }

    merge(arr, left, mid, right);
}

int main() {
    const int N = 1000000;
    std::vector<int> arr1(N);
    std::vector<int> arr2(N);

    std::mt19937 rng(42);
    for (int i = 0; i < N; ++i) {
        int val = rng() % 1000000;
        arr1[i] = val;
        arr2[i] = val;
    }

    auto startSeq = std::chrono::high_resolution_clock::now();
    sequentialMergeSort(arr1, 0, N - 1);
    auto endSeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> seqDuration = endSeq - startSeq;

    auto startPar = std::chrono::high_resolution_clock::now();
    parallelMergeSort(arr2, 0, N - 1);
    auto endPar = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> parDuration = endPar - startPar;

    std::cout << "Parallel Algorithm Benchmark: Merge Sort" << std::endl;
    std::cout << "Dataset Size:               " << N << " elements" << std::endl;
    std::cout << "Sequential Merge Sort Time: " << seqDuration.count() << " ms" << std::endl;
    std::cout << "Parallel Merge Sort Time:   " << parDuration.count() << " ms" << std::endl;
    std::cout << "Speedup Factor:             " << seqDuration.count() / parDuration.count() << "x" << std::endl;
    std::cout << "Verification (Sorted):      " << (std::is_sorted(arr2.begin(), arr2.end()) ? "PASSED" : "FAILED") << std::endl;

    return 0;
}


