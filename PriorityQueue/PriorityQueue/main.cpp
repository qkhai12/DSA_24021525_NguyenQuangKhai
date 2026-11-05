#include <iostream>
using namespace std;

int pq[100001];
int n = 0;

bool less_(int i, int j)
{
    return pq[i] < pq[j];
}

void exch(int i, int j)
{
    swap(pq[i], pq[j]);
}

// day phan tu k len (dung sau insert)
void swim(int k)
{
    while (k > 1 && less_(k / 2, k)) {
        exch(k, k / 2);
        k = k / 2;
    }
}

// day phan tu k xuong (dung sau delMax)
void sink(int k)
{
    while (2 * k <= n) {
        int j = 2 * k;

        if (j < n && less_(j, j + 1)) {
            j++;                // j la con lon hon
        }

        if (!less_(k, j)) {
            break;
        }

        exch(k, j);
        k = j;
    }
}

void insert(int x)
{
    n++;
    pq[n] = x;
    swim(n);
}

int max()
{
    return pq[1];
}

int delMax()
{
    int res = pq[1];

    exch(1, n);
    n--;
    sink(1);

    return res;
}

bool isEmpty()
{
    return n == 0;
}

int size()
{
    return n;
}

int main()
{
    int m;

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    cout << "max = " << max() << endl;
    cout << "size = " << size() << endl;

    while (!isEmpty()) {
        cout << delMax() << " ";
    }

    cout << endl;

    return 0;
}
