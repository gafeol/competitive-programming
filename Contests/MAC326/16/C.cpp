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

int n, m, k;
ll f[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll gcd(ll a, ll b, ll *x, ll *y)
{
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1; 
    ll gc = gcd(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gc;
}

double gd = (1 + sqrt(5))/2.;
pii res;

void solve(int x, int ult){
	if(x <= 0 || x > ult) return ;
	res = min(res, {ult, x});
	solve(ult - x, x);
}

int main (){
	for_tests(t, tt){
		res = {INT_MAX, INT_MAX};
		scanf("%d", &n);
		int x = (n/gd);
		solve(x, n);
		solve(x-1, n);
		solve(x+1, n);
		printf("%d %d\n", res.snd, res.fst);
	}
}

