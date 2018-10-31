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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN];


ll mx, sum;
ll res;
ll soma[MAXN], cnt[MAXN];
void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


void add(ll x){
    mx = max(mx,(ll) __builtin_popcountll(x));
    sum += __builtin_popcountll(x);
}

int ok(){
    if((sum&1ll)) return 0;
    return (sum/2ll >= mx);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        mx = 0;
        sum = 0;
        for(int b=a;b >= 0 && b>= a-70;b--){
            add(s[b]);  
            res += ok();
        }
        ll nb = __builtin_popcountll(s[a]);
        soma[a] =  (a > 0 ? soma[a-1] : 0ll) + nb;
        ll o = (soma[a]&1ll); 
        res += cnt[o] + (a > 70 && o == 0);
        if(a - 71 >= 0)
            cnt[(soma[a-71]&1ll)]++;
	}
    printf("%lld\n", res);
}

