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

const int MAXN = 1123456;

ll n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> pri;

vector<ll> f, cnt;

ll count (ll x){
    ll nn = n;
    ll ans = 0;
    while(n > 0){
        ans += n/x;
        n /= x;
    }

    n = nn;
    return ans;
}
int mrk[MAXN];

int main (){
    for(int a=2;a<MAXN;a++){
        if(mrk[a]) continue;
        pri.pb(a);
        for(ll b = a;a*b < MAXN;b++){
            mrk[a*b] = 1;
        }
    }

    for_tests(t, tt){
        scanf("%lld%lld", &n, &k);
        f.clear();
        cnt.clear();
        for(int p: pri){
            if(k%p != 0) continue;
            int aux = 0;
            while(k%p == 0){
                k /= p;
                aux++;
            }
            f.pb(p);
            cnt.pb(aux);
        }
        if(k != 1){
            f.pb(k);
            cnt.pb(1);
        }
        ll res = LLONG_MAX;
        for(int i=0;i<f.size();i++){
            res = min(count(f[i])/cnt[i], res);
        }
        printf("%lld\n", res);
    }
}

