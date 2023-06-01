#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printHeap(vector<int>& a) {
    int in = 1;
    int layer = 0;
    int j = 0;
    layer = log2((int)a.size()) + 1;
    // for (auto p = a.rbegin(); p != a.rend(); p = p) {
    for (int i = 0; i < layer; i = i) {
        for (int k = 0; k < pow(2, layer - i); k++)
            cout << "  ";
        cout << a.at(j);
        for (int k = 0; k < pow(2, layer - i); k++)
            cout << "  ";
        if (j == pow(2, in) - 2) {
            cout << endl;
            i++;
            in++;
        }
        j++;
        if (j == (int)a.size())
            break;
    }
    cout << endl;
    // }
    // cout << "hihi" << endl;
}

// void printHeap(const vector<int>& heap) {
//     int n = heap.size();
//     int levels = 0;
//     int levelNodes = 1;

//     while (n > 0) {
//         for (int i = 0; i < levelNodes && n > 0; ++i) {
//             cout << heap[heap.size() - n] << "\t";
//             --n;
//         }

//         cout << endl;

//         levels++;
//         levelNodes = levelNodes * 2;
//     }
// }

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1], ios::binary);

    if (!inputFile) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    vector<int> inputNumbers;
    int num;

    while (inputFile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        inputNumbers.push_back(num);
    }

    // cout << "Input Numbers: ";
    // for (int num : inputNumbers) {
    //     cout << num << " ";
    // }
    // cout << endl;

    vector<int> heap(inputNumbers);
    make_heap(heap.begin(), heap.end(), greater<int>());

    // cout << "Min Heap before 1 reaches the top:" << endl;
    printHeap(heap);

    heap[0] = 1;  // Set the root as 1

    // cout << "Min Heap after 1 reaches the top:" << endl;
    // printHeap(heap);

    heapSort(heap);

    // cout << "Heap Sorted Array: ";
    for (auto p = heap.rbegin(); p != heap.rend(); p++) {
        cout << *p << " ";
    }
    cout << endl;

    inputFile.close();

    return 0;
}

