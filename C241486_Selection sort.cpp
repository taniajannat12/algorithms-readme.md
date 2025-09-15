#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int i = 0; i < n - 1; i++) {
        int MIN = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[MIN])
                MIN= j;

        int temp = a[i];
        a[i] = a[MIN];
        a[MIN] = temp;
    }


    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

