#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Data parsing
    int n, k;

    cin >> n >> k;

    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Computing
    // n -> number of beads, dp[][x][] -> current streak, dp[][][x] -> use of K
    int dp[n][0][0];

    for (int i = 0; i < n; i++) {

    }
}