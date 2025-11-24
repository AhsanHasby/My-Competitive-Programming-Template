/*
██████╗░██╗░██████╗███╗░░░███╗██╗██╗░░░░░██╗░░░░░░█████╗░██╗░░██╗
██╔══██╗██║██╔════╝████╗░████║██║██║░░░░░██║░░░░░██╔══██╗██║░░██║
██████╦╝██║╚█████╗░██╔████╔██║██║██║░░░░░██║░░░░░███████║███████║
██╔══██╗██║░╚═══██╗██║╚██╔╝██║██║██║░░░░░██║░░░░░██╔══██║██╔══██║
██████╦╝██║██████╔╝██║░╚═╝░██║██║███████╗███████╗██║░░██║██║░░██║
╚═════╝░╚═╝╚═════╝░╚═╝░░░░░╚═╝╚═╝╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝*/
#include<bits/stdc++.h>
using namespace std;

// =================== Typedefs ===================
using ll   = long long;
using ull  = unsigned long long;
using str  = string;
using vin  = vector<int>;
using vll  = vector<ll>;
// =================== Constants ===================
const char endL = '\n';
const int  IMAX  = 1e9;
const ll   LMAX  = 1e18;
const ll   MOD  = (1e9+7); //if given
// =================== Fast IO ===================
#define WAKE    ios_base::sync_with_stdio(false);
#define UP_TO   cin.tie(nullptr);
#define REALITY cout.tie(nullptr);
// =================== Macros ===================
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (int)(x.size())
#define eb       emplace_back //try_emplace(1 insrt)

#define Unique(x) x.erase(unique(all(x)), x.end())

#define print(arr) for(auto &it:(arr)) cout << it << " "; cout << endL;
#define YES     cout << "YES\n"
#define NO      cout << "NO\n"
//================= MAIN CODE ===============

bool UniversalPull() {

    return true; 
}

void DomainExpansion() {
    int n, s; cin >> n >> s;
    vin a(n);
    int sum = 0;
    vin pre;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if(a[i]) pre.eb(i+1);
    }

    if(sum < s) {
        cout << -1 << endL;
        return;
    }
    else  if(sum == s) {
        cout << 0 << endL;
        return;
    }

    vin suf;
    for(int i = n-1; i >= 0; --i) {
        if(a[i]) suf.eb(n-i);
    }

    int ops1 = 0, ops2 = 0;
    for(int i = 0, j = 0; sum > s; --sum) {
        if(pre[i] == suf[j]) {
            if(ops1 < ops2) {
                ops2 = suf[j];
                ++j;
            }
            else {
                ops1 = pre[i];
                ++i;
            }
        }
        else if(pre[i] < suf[j] && i < sz(pre)) {
            ops1 = pre[i];
            ++i;
        }
        else if(j < sz(suf)) {
            ops2 = suf[j];
            ++j;
        }
    }

    cout << ops1 + ops2 << endL;

}

// Bismillah...
int main() {
    WAKE UP_TO REALITY

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    //test cases
    int test = 1;
    cin >> test;
    //cin.ignore();

    for(int i = 1; i <= test; i++) {
        //cout << "Case " << i <<": ";
        DomainExpansion();
    }
    return 0;
}