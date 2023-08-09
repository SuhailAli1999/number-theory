#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define F first
#define S second
const int mod = 1e7;
const int N = 1e7;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

// custom sort in priority queue
struct cmp1 {

    bool operator()(pair<int, int> const& a, pair<int, int> const& b){
      if(a.first == b.first){
            return a.second > b.second;
        }
        else {
         return a.first < b.first;
        }
    }
};


ll fix_mod(ll a, ll b){
    return (a % b + b) % b;
}

vector<int> get_divisors(int n){ // o(sqrt(n)) //factoring
    vector<int> ans;
    for(int i=1; i*i<= n; i++){
        if(n%i==0){
            ans.push_back(i);
            if(i*i != n){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

vector<int> get_multiples(int x, int n){
    vector<int> ans;
    for(int m=x; m<=n; m+=x){
        ans.push_back(m);
    }
    return ans;
}

bool is_prime(int n){ // o(sqrt(n))
    if(n==1) return false;
    for(int p=2; p*p <= n; p++){
        if(n%p==0){
            return false;
        }
    }
    return true;
}

void sieve(int isPrime[], int N){ // o(n) -- o(n log(log(n)))
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for(int p=2; p*p<N; p++){
        if (isPrime[p]){
            for(int m = p*p; m<N; m+=p){
                isPrime[m] = false;
            }
        }
    }
}

void prime_factorization_sieve(int isPrime[], int N){ // o(n) -- o(n log(log(n)))
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for(int p=2; p<N; p++){
        if (isPrime[p] == 1){
            for(int m = p; m<N; m+=p){
                if(isPrime[m] == 1) isPrime[m]=p;
            }
        }
    }
}

vector<int> prime_factorization(ll n){ //o(sqrt(n))
    vector<int> ans;
    for (int p=2; p*p<=n; p++){
        while(n%p == 0){
            n/=p;
            ans.push_back(p);
        }
    }
    if(n!=1){
        ans.push_back(n);
    }

    return ans;
}

int fastPower(int base, int power){
    if(power == 0) return 1;
    if(power == 1) return base;
    ll half = fastPower(base, power/2);
    ll ans = half*half;
    // if base odd
    if(power%2) ans*=base;
    return ans;
}

ll modInv(ll n) {
    return fastPower(n, mod - 2);
}

ll fact[N], inv[N];

ll factorial(ll n){ // n! ---> o(n)
    vector<ll> v(n+1);
    v[0] = 1;
    for(int i=1; i<=n; i++){
        v[i] = v[i-1] * i;
        v[i]%= mod;
        inv[i] = fastPower(fact[i], mod - 2);
    }
    return v[n];
}

ll nCr(ll n, ll r) {
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll nPr(ll n, ll r) {
    return ((fact[n] * inv[n - r])) % mod;
}

//complete search
void complete_search (int n){
    for(int mask=0; mask <(1<<n); mask++){
        for(int i=0; i<n; i++){
           if(((mask>>i)&1)){ // isOn
            cout << 1 << " ";
           }
           else{
            cout << 0 << " ";
           }
        }
        cout << endl;
    }
}

bool is_perfect_square(long double x){
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

void solve(){

}


int main(){
    //freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    //freopen("second_friend_output.txt", "w", stdout);
    fast();
    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }
        return 0;
    }
