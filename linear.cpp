#include <iostream>
using namespace std;

int main() {
    int n, key, i;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = true;
            break;
        }
    }

    if(found)
        cout << key << " is found at position " << i+1 << endl;
    else
        cout << key << " is not found" << endl;

    return 0;
}
