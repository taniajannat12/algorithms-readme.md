#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int maxVal = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    int count[maxVal + 1] = {0};


    for(int i = 0; i < n; i++)
        count[arr[i]]++;


    for(int i = 0; i <= maxVal; i++) {
        while(count[i] > 0) {
            cout << i << " ";
            count[i]--;
        }
    }
    cout << endl;
    return 0;
}

