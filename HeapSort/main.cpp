#include <iostream>
using namespace std;



int a[100001];

void swim(int k)
{
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k], a[k / 2]);
        k = k / 2;
    }
}

// sink phan tu k trong heap co n phan tu
void sink(int k, int n)
{
    while (2 * k <= n) {
        int j = 2 * k;

        if (j < n && a[j] < a[j + 1]) {
            j++;
        }

        if (a[k] >= a[j]) {
            break;
        }

        swap(a[k], a[j]);
        k = j;
    }
}

void heapSort(int n)
{
    // Phase 1: xay max heap
    for (int k = 1; k <= n; k++) {
        swim(k);
    }

    // Phase 2: sortdown
    int k = n;
    while (k > 1) {
        swap(a[1], a[k]);
        k--;
        sink(1, k);
    }
}

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    heapSort(n);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
