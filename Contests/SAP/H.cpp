#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int MAXN = 2123;

int n, m, k;
pll s[MAXN];

ll sq(ll x){
    return x*x;
}

int pai[MAXN], sz[MAXN];

int raiz(int i){
    if(pai[i] == i) return i;
    return pai[i] = raiz(pai[i]);
}

bool join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return false;

    if(sz[i] < sz[j]) swap(i, j);

    pai[j] = i;
    sz[i] += sz[j];
    return true;
}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        pai[a] = a;
        sz[a] = 1;
        ll x, y;
        scanf("%lld %lld", &x, &y);
        s[a] = {x, y};
	}
    vector<tuple<double, int , int> > ar;
    for(int a=0;a<n;a++){
        for(int b=a+1;b<n;b++){
            ll d = sq(s[a].fst - s[b].fst) + sq(s[a].snd - s[b].snd);   
            ar.pb({sqrt((double)d), a, b});
        }
    }
    sort(ar.begin(), ar.end());
    double res = 0;
    for(tuple<double, int, int> t: ar){
        double d;
        int u, v;
        tie(d, u, v) = t;
        if(join(u, v))
            res += d;
    }
    printf("%.10lf\n", res);

}

