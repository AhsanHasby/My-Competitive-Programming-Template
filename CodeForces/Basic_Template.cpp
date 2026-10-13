#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 5;
const ll MAX = 1e9 + 5;

void gear2() {
    ll n, a, b; cin >> n >> a >> b;
    ll cost = 0;
    for(int i = 0; i < n; ++i) {
        if(a >= b-i) {
            cost += (n-i)*a;
            break;
        }
        cost += b-i;
    }
    cout << cost << "\n";

}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int test;
    cin >> test;
    while (test--) gear2();
    
    return 0;
}