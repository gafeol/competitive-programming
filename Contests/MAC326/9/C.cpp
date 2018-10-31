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
const ll modn = 123456789;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

ll dp[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d%d", &n, &k);
    dp[1] = 1; 
    ll sum = 1;
    int ult = 0;
    for(int a=2;a<=n;a++){
        if(a - ult > k){
            sum = mod(modn + mod(sum - dp[ult]));
            ult++;
        }
        dp[a] = sum;
        sum = mod(sum + dp[a]);
    }
    ll res = 0;
    for(int a=n;a>n-k;a--){
        res = mod(res + mod(dp[a]*(n-a+1ll)));
    }
    printf("%lld\n", res);
}
