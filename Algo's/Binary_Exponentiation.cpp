#include<bits/stdc++.h>
using namespace std;

// Typedefs
using ll   = long long;
using ull  = unsigned long long;
// Constants
const char endL = '\n';
const ll   MOD  = (1e9+7);
// Fast IO
#define NAH    ios_base::sync_with_stdio(false);
#define I_D   cin.tie(nullptr);
#define WIN cout.tie(nullptr);

//==========(->MAIN CODE<-)==========

ll binaryExponentiation(ll x, ll n) {
    ll result = 1;

    ll base = x % MOD;
    ll exp = n;
    while (exp > 0) {
        if(exp & 1) {
            result = (result*base) % MOD;
        }

        base = (base*base) % MOD;
        exp >>= 1;
    }

    return result;
    
}

void gear2() {
    ll x, n;
    cin >> x >> n; // (x)^n

    ll x_power_n = binaryExponentiation(x, n);

    cout << x_power_n << endL;
}

int main() {
    NAH I_D WIN

    //test cases
    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i++) {
        //cout << "Case " << i <<": ";
        gear2();
    }
    return 0;
}