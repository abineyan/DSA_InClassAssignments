#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
using namespace std;
using namespace std::chrono;



int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quicksort_recursive(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort_recursive(arr, left, pivotIndex - 1);
    quicksort_recursive(arr, pivotIndex + 1, right);
}

void quicksort(vector<int>& arr) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(0, arr.size() - 1));

    while (!stk.empty()) {
        int l = stk.top().first;
        int r = stk.top().second;
        stk.pop();

        if (l >= r) {
            continue;
        }

        int pivotIndex = partition(arr, l, r);
        stk.push(make_pair(l, pivotIndex - 1));
        stk.push(make_pair(pivotIndex + 1, r));
    }
}

int main() {
    const int n = 2000000; // size of the vector
    vector<int> input_vector;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers and fill the vector
    for (int i = 0; i < n; i++) {
        input_vector.push_back(rand() % 100 + 1); // generate a random number between 1 and 100
    }

   // Measure execution time
    auto start = high_resolution_clock::now();
   
    quicksort(input_vector);
    //quicksort_recursive(input_vector, 0, input_vector.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken: "
        << duration.count() << " microseconds" << endl;

   return 0;
}
