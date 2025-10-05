#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int n = str1.size();
    int m = str2.size();

    // Create a 2D dp array
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Fill dp table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Print length of LCS
    cout << "Length of LCS: " << dp[n][m] << endl;
}
