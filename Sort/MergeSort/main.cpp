#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = a[l + i];
    }

    for (int i = 0; i < n2; i++) {
        arr2[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            a[k] = arr1[i];
            i++;
        }
        else {
            a[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main()
{
    int a[100000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
