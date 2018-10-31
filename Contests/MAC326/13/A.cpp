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
const double EPS = 1e-8;

int n, m;
double k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<double> v;

int main (){
    while(scanf("%d%d%lf", &n, &m, &k) != EOF && n+m+k > 0.){
        k = k/2.;
        int ok = 1;
        for(int a=0;a<n;a++){
            double x;
            scanf("%lf", &x);
            v.pb(x);
        }

        double i = 0, j = 75;
        sort(v.begin(), v.end());
        for(double p: v){
            if(i + k + EPS < p)
                break;
            i = p + k;
        }
        if(i + EPS < j)
            ok = 0;

        v.clear();
        for(int a=0;a<m;a++){
            double x;
            scanf("%lf", &x);
            v.pb(x);
        }

        i = 0.; j = 100.;
        sort(v.begin(), v.end());
        for(double p: v){
            if(i + k + EPS < p)
                break;
            i = p + k;
        }
        if(i + EPS < j)
            ok = 0;
        v.clear();

        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}

