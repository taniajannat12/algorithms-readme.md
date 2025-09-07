#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int k, pos = -1;
    cout << "Enter element to search: ";
    cin >> k;

    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == k) {
            pos = mid;
            break;
        } else if(a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if(pos == -1)
        cout << k << " is not found" << endl;
    else
        cout << k << " is found at position " << pos + 1 << endl;
}
