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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> adj[MAXN];

vector<int> v[MAXN];

int d[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i].pb(j);
        adj[j].pb(i);
	}
    int mx = 0;
    for(int a=0;a<n;a++){
        v[adj[a].size()].pb(a);
        mx = max(mx, (int)adj[a].size());
    }
    int res = 0;
    for(int a=mx;a>=0;a--){
       for(int u: v[a]){
           res = max(res, d[u]);
           for(int nxt: adj[u]){
                if(adj[nxt].size() >= a) continue;
                d[nxt] = max(d[nxt], d[u]+1);
           }
       }
    }
    printf("%d\n", res+1);
}

