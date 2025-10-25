#include <bits/stdc++.h>
using namespace std;
void mergeArray(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
        a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    cout << "After merge (" << l << "," << mid << "," << r << "): ";
    for (int t = l; t <= r; t++)
        cout << a[t] << " ";
    cout << endl;
}

void mergeSort(int a[], int l, int r) {
    if (l< r) {
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeArray(a, l, mid, r);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    mergeSort(a, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}



