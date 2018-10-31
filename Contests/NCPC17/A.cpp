#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long double, int> pdi;
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

const int MAXN = 512345;

int n, m, k;
ll l, A, B, t, r;
ll s[MAXN];

int bef[MAXN];
vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool end(int i, int j){
    ll d = s[j] - s[i];
    if(d <= t*A)
        return false;
    return (d > t*A + B*r);
}

long double dis(int i, int j){
    ll d = s[j] - s[i];
    if(d <= t*A)
        return ((long double)d)/A;
    long double ans = t;
    d -= t*A;
    if(d <= r*B)
        return ans + ((long double)d)/B;
    ans += r;
    d -= r*B;
    return ((long double)d)/A + ans;
}

long double d[MAXN];

void di(int i, int j){
    //printf("i %d -> j %d: %.5f\n", i, j, dis(i, j));
}

int main (){
	scanf("%lld%lld%lld%lld%lld", &l, &A, &B, &t, &r);
    scanf("%d", &n);
    if(n == 0){
        puts("0");
        return 0;
    }
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
	}
    sort(s, s+n);
    s[n] = l;

    int i = 0, j = 0;
    while(i < n){
        while(j < n && !end(i, j)) 
            j++;
        ///printf("i %d -> %d %d %d\n", i, i+1, j-1, j);
        adj[i].pb(j);
        if(j-1 > i)
            adj[i].pb(j-1);
        if(i+1 < j-1)
            adj[i].pb(i+1);
        i++;
    }
    for(int a=0;a<=n;a++)
        d[a] = DBL_MAX;
    d[0] = 0;
    set<pdi> q;
    q.insert(pdi(0, 0)); 
    while(!q.empty()){
        pdi top = *q.begin();
        q.erase(q.begin());
        int u = top.snd;
        //printf("u %d d %.10f\n", u, top.fst);
        for(int nxt: adj[u]){
            if(d[nxt] > d[u] + dis(u, nxt)){
                if(d[nxt] != DBL_MAX)
                    q.erase(pdi(d[nxt], nxt));
                d[nxt] = d[u] + dis(u, nxt);
                bef[nxt] = u;
                q.insert(pdi(d[nxt], nxt));
            }
        }
    }
    int u = n;
    vector<int> ans;
    while((u = bef[u]) != 0)
        ans.pb(u);
    ans.pb(0);
    printf("%d\n", (int)ans.size());
    for(int a=ans.size()-1;a>=0;a--){
        printf("%d ", ans[a]);
    }
    puts("");
}

