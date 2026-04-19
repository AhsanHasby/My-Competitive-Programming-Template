/*
██████╗░██╗░██████╗███╗░░░███╗██╗██╗░░░░░██╗░░░░░░█████╗░██╗░░██╗
██╔══██╗██║██╔════╝████╗░████║██║██║░░░░░██║░░░░░██╔══██╗██║░░██║
██████╦╝██║╚█████╗░██╔████╔██║██║██║░░░░░██║░░░░░███████║███████║
██╔══██╗██║░╚═══██╗██║╚██╔╝██║██║██║░░░░░██║░░░░░██╔══██║██╔══██║
██████╦╝██║██████╔╝██║░╚═╝░██║██║███████╗███████╗██║░░██║██║░░██║
╚═════╝░╚═╝╚═════╝░╚═╝░░░░░╚═╝╚═╝╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝*/
#include<bits/stdc++.h>
using namespace std;

// Typedefs
using ll   = long long;
using ull  = unsigned long long;
using vin  = vector<int>;
using vll  = vector<ll>;
// Constants
const char endL = '\n';
const ll   MOD  = (1e9+7); //if given
// Fast IO
#define WAKE    ios_base::sync_with_stdio(false);
#define UP_TO   cin.tie(nullptr);
#define REALITY cout.tie(nullptr);
// Macros
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x)   (int)(x.size())
#define eb       emplace_back //try_emplace(1 insrt)

#define Unique(x) x.erase(unique(all(x)), x.end())

#define print(arr) for(auto &it:(arr)) cout << it << " "; cout << endL;
#define YES     cout << "YES\n"
#define NO      cout << "NO\n"

//==========(->MAIN CODE<-)==========

bool UniversalPull() {

    return true; 
}

void DomainExpansion() {
    ll n, m, k;
    cin >> n >> m >> k;
    vll robs(n);
    for(int i = 0; i < n; ++i) cin >> robs[i];
    set<ll> spik;
    for(int i = 0; i < m; ++i){
        ll x; cin >> x;
        spik.insert(x);
    }
    string s;
    cin >> s;

    map<ll, ll> RC;
    for(auto i : robs) RC[i]++;
    ll alive = n;
    vll ans;
    for(char mv : s){
        map<ll, ll> tmp;
        ll dead = 0;

        for(auto &[pos, cnt] : RC) {
            ll x = (mv == 'L') ? pos-1 : pos+1;
            if(spik.count(x)) dead += cnt;
            else tmp[x] += cnt;
        }

        alive -= dead;
        RC = tmp;
        ans.eb(alive);
    }

    print(ans);
}


int main() {
    WAKE UP_TO REALITY

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
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