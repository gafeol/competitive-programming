#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

const double EPS = 1e-8;
const double LEN  = 10000.;

int main (){
    freopen("graveyard.in", "r", stdin);
    freopen("graveyard.out", "w", stdout);
	scanf("%d%d", &n, &m);
    vector<double> npos;
    npos.pb(-LEN);
    for(int a=0;a<n+m;a++)
        npos.pb((LEN/(n+m))*a);
    npos.pb(LEN);
    double res = 0;
    for(int a=0;a<n;a++){
        double x = (LEN/n) * a;
        res += min(abs(x - *lower_bound(npos.begin(), npos.end(), x-EPS)),
                min(
                    abs(x - *(--lower_bound(npos.begin(), npos.end(), x-EPS))),
                    abs(x - *lower_bound(npos.begin(), npos.end(), x+EPS))));
    }
    printf("%.10f\n", res);
}

