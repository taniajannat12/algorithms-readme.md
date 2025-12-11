#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "How many characters? ";
    cin >> n;
    char ch[100];
    int fr[100];
    cout << "Enter character and frequency:\n";
    for(int i = 0; i < n; i++){
        cin >> ch[i] >> fr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(fr[j] < fr[i]){
                swap(fr[i], fr[j]);
                swap(ch[i], ch[j]);
            }
        }
    }
    string code[100];
    for(int i=0; i<n; i++) code[i] = "";

    priority_queue<pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>> pq;
    for(int i=0; i<n; i++){
        string s = "";
        s += ch[i];
        pq.push({fr[i], s});
    }
    while(pq.size() > 1){
        auto left = pq.top();  pq.pop();
        auto right = pq.top(); pq.pop();

        for(char c : left.second){
            for(int i=0; i<n; i++){
                if(ch[i] == c) code[i] = "0" + code[i];
            }
        }
        for(char c : right.second){
            for(int i=0; i<n; i++){
                if(ch[i] == c) code[i] = "1" + code[i];
            }
        }
        pq.push({ left.first + right.first,
                  left.second + right.second });
    }
    cout << "\nCHAR   FREQ   CODE    (freq x length)\n";
    int totalBits = 0;
    for(int i = 0; i < n; i++){
        int bits = fr[i] * code[i].length();
        totalBits += bits;

        cout << ch[i] << "      "
             << fr[i] << "      "
             << code[i] << "        "
             << bits << endl;
    }
    int headerBits = n*8;
    int treeBits = n - 1;
    int VL = headerBits + totalBits + treeBits;
    cout << "\nTotal encoded bits = " << totalBits << endl;
    cout << "Header bits = " << headerBits << endl;
    cout << "Tree bits = " << treeBits << endl;
    cout << "VL = " << headerBits << " + " << totalBits
         << " + " << treeBits << " = " << VL << endl;
}
