#include <algorithm>
#include <iostream>
using namespace std;

void heapify(int *a, int i, int n) {
    int largest = i;
    const int l = 2 * i + 1;
    const int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;

    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        std::swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int *a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

void build_maxheap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, i, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements of array\n";
    cin >> n;
    int a[20];
    for (int i = 0; i < n; ++i) {
        cout << "Enter Element " << i << std::endl;
        cin >> a[i];
    }

    build_maxheap(a, n);
    heapsort(a, n);
    cout << "Sorted Output\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    // getchar();
}
