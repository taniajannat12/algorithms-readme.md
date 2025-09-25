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


    for(int exp = 1; maxVal/exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};


        for(int i = 0; i < n; i++)
            count[(arr[i]/exp)%10]++;


        for(int i = 1; i < 10; i++)
            count[i] += count[i-1];


        for(int i = n-1; i >= 0; i--) {
            int digit = (arr[i]/exp)%10;
            output[count[digit]-1] = arr[i];
            count[digit]--;
        }


        for(int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

