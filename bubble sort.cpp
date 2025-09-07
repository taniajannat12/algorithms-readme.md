
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int temp, flag;
    for(int i=0; i<n-1; i++) {
        flag = 0;
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
