#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
 
// a * b % m
inline long long mul_mod(long long a, long long b, long long m) {
    long long x = 0, y = a%m;
    while (b) {
        if (b % 2)
            x = (x+y)%m;
        y = (2*y)%m;
        b >>= 1;
    }
    return x%m;
}
 
// n ^ e % m
inline long long exp_mod(long long n, long long e, long long m) {
    if (e == 0)
        return 1ll;
    long long temp = exp_mod(mul_mod(n, n, m), e/2, m);
    if (e & 1)
        temp = mul_mod(n, temp, m);
    return temp;
}
 
inline long long pollard_rho(long long n) {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> distrib(2, n-1);
    long long x = distrib(rng), y = x, c = distrib(rng), factor;
    do {
        x = (mul_mod(x, x, n) + c) % n;
        y = (mul_mod(y, y, n) + c) % n;
        y = (mul_mod(y, y, n) + c) % n;
        factor = __gcd(abs(y - x), n);
    } while (factor == 1);
    if (factor == n)
        return 0;
    return factor;
}
 
// complexity: O(t*log2^3(p))
inline bool is_probably_prime(long long p, long long t=64) {
    if (p <= 1) return false;
    if (p <= 3) return true;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> distrib(2, p - 2);
    long long r = 0, d = p - 1;
    while (d % 2 == 0) {
        r++;
        d >>= 1;
    }
    while (t--) {
        long long a = distrib(rng);
        a = exp_mod(a, d, p);
        if (a == 1 || a == p - 1) continue;
        for (int i = 0; i < r - 1; i++) {
            a = mul_mod(a, a, p);
            if (a == 1) return false;
            if (a == p - 1) break;
        }
        if (a != p - 1) return false;
    }
    return true;
}
 
#define fst first
#define snd second
#define pb push_back
typedef long long ll;
 
vector<pair<ll, int> f;
void div_rec(vector<ll>& r, int k, ll c){
    if(k==f.size()){r.pb(c);return;}
    for(int i=0; i < f[k].snd+1; i++) div_rec(r,f,k+1,c),c*=f[k].fst;
}
inline vector<ll> divisors(vector<pair<ll,int> > f){
    f = 
    vector<ll> r; // returns divisors given factorization
    div_rec(r,f,0,1);
    return r;
}
 
const long long M = 1000000;
 
int32_t main() {
    long long n; scanf("%lld", &n);
    long long nnn=n;
    n = 2 * (n + 1);
    long long nn = n;
    n = n * n - 2 * n;
    vector<pair<long long, int>> primes;
    for (long long i = 2; i <= min(n, M); i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            primes.push_back({i, cnt});
        }
    }
    if (n != 1) {
        if (is_probably_prime(n)) {
            primes.push_back({n, 1});
        } else {
            while (long long k = pollard_rho(n) != 0) {
            	if(k*k==n){primes.push_back({k, 2});}
            	else{
            		primes.push_back({k, 1});
                    primes.push_back({n / k, 1});
            	}
            }
        }
    }
    vector<long long> div = divisors(primes);
    set<pair<long long, long long>> res;
    for (auto d: div) {
        long long b = d + nn;
        long long a = (nn * (b - 2)) / d;
        if(nnn*(2*(a-1)+2*(b-1))==(a-2)*(b-2))
        	res.insert({min(a, b), max(a, b)});
    }
    printf("%d\n", (int)res.size());
    for (auto a: res) {
        printf("%lld %lld\n", a.first, a.second);
    }
}
