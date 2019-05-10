#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int s[MAXN];
int mrk[MAXN];
ll n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

multiset<ll> f[3];
vector<ll> pri;

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
    ll on = n, om = m;
    ll gc = gcd(n*m, k);
    ll ar = (n*m)/gc;
    k /= gc;
    if(k > 2){
        puts("NO");
        return 0;
    }
    puts("YES");

    for(ll a=2;a<1e5;a++){
        if(mrk[a]) continue;
        pri.pb(a);
        for(ll b=a;b*a <= 1e5+2;b++)
            mrk[b*a] = 1;
    }
    for(ll p: pri){
        while(n > 0 && n%p == 0){
            n /= p;
            f[0].insert(p);
        }
    }
    if(n > 1)
        f[0].insert(n);
    for(ll p: pri){
        while(m > 0 && m%p == 0){
            m /= p;
            f[1].insert(p);
        }
    }
    if(m > 1)
        f[1].insert(m);

    for(ll p: pri){
        while(gc > 0 && gc%p == 0){
            gc /= p;
            if(f[0].find(p) != f[0].end())
                f[0].erase(f[0].find(p));
            else
                f[1].erase(f[1].find(p));
        }
    }
    if(gc > 1){
        ll p = gc;
        if(f[0].find(p) != f[0].end())
            f[0].erase(f[0].find(p));
        else
            f[1].erase(f[1].find(p));
    }
    ll mul[3];
    mul[0] = mul[1] = 1;
    for(int t=0;t<2;t++){
        for(auto it: f[t]){
           mul[t] *= it; 
        }
    }
    if(k == 1){
        if(mul[0]*2ll <= on)
            mul[0]*= 2ll;
        else
            mul[1]*=2ll;
    }
    assert(mul[0] <= on);
    assert(mul[1] <= om);
    printf("%lld %lld\n", 0ll, 0ll);
    printf("%lld %lld\n", mul[0], 0ll);
    printf("%lld %lld\n", 0ll, mul[1]);
}
