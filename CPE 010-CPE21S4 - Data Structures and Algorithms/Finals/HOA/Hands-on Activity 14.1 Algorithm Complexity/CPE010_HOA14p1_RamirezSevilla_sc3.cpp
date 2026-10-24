#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

// Linear Search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];

        vector<int> arr(n);

        // Create a sorted array
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        // Target is absent to test worst-case searching
        int target = -1;

        // Measure Binary Search
        auto startBinary = steady_clock::now();

        int resultBinary = binarySearch(arr, target);

        auto endBinary = steady_clock::now();

        auto binaryTime =
            duration_cast<nanoseconds>(
                endBinary - startBinary
            ).count();

        // Measure Linear Search
        auto startLinear = steady_clock::now();

        int resultLinear = linearSearch(arr, target);

        auto endLinear = steady_clock::now();

        auto linearTime =
            duration_cast<nanoseconds>(
                endLinear - startLinear
            ).count();

        // Display results
        cout << "Input Size: " << n << endl;

        cout << "Worst Case Binary Search Algorithm's Time: "
             << binaryTime << " nanoseconds" << endl;

        cout << "Worst Case Linear Search Algorithm's Time: "
             << linearTime << " nanoseconds" << endl;
    }

    return 0;
}
