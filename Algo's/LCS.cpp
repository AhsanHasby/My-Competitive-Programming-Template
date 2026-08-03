#include<bits/stdc++.h>
using namespace std;

// Typedefs
using ll   = long long;
using ull  = unsigned long long;
// Constants
const char endL = '\n';
const ll   MOD  = (1e9+7);
const ll   INF  = 1e18; // Infinity for initial distances

// Fast IO
#define NAH   ios_base::sync_with_stdio(false);
#define I_D   cin.tie(nullptr);
#define WIN   cout.tie(nullptr);

//==========(->MAIN CODE<-)==========

pair<int, string> getLCS(string &X, string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i-1] == Y[j-1]) { // compare string index - if match
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // backtracking for lcsString sequence
    string lcsString = "";
    int i = m, j = n;
    while (i && j) {
        if (X[i-1] == Y[j-1]) {
            lcsString += X[i-1];
            --i;
            --j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        }
        else --j;
    }

    reverse(lcsString.begin(), lcsString.end());
    return {dp[m][n], lcsString};

}

void gear2() {
    string s1, s2;
    cin >> s1 >> s2;

    auto [len, lcsString] = getLCS(s1, s2);

    cout << len << ": " << lcsString;
    cout << endL;
}

int main() {
    NAH I_D WIN

    //test cases
    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i++) {
        //cout << "Case " << i <<":\n";
        gear2();
    }
    return 0;
}