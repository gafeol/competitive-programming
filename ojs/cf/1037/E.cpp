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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii ar[MAXN];
int mrk[MAXN];
int deg[MAXN];
vector<pii> adj[MAXN];

set<pii> q;

void dim(int u){
    if(deg[u] == 0) return;
    q.erase(pii(deg[u], u));
    deg[u]--;
    if(deg[u] > 0)
        q.insert(pii(deg[u], u));
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        deg[i]++;
        deg[j]++;
        ar[a] = pii(i, j);
        adj[i].pb(pii(j, a));
        adj[j].pb(pii(i, a));
	}
    for(int a=1;a<=n;a++){
        q.insert(pii(deg[a], a));
    }
    stack<int> ans;
    for(int a=m-1;a>=0;a--){
        while(!q.empty() && q.begin()->fst < k){
            int u = q.begin()->snd;
            q.erase(pii(deg[u], u));
            deg[u] = 0;
            for(pii ares: adj[u]){
                int nxt = ares.fst;
                int ind = ares.snd;
                if(mrk[ind]) continue;
                mrk[ind] = 1;
                dim(nxt);
            }
        }

        ans.push((int)q.size());
        if(mrk[a]) continue;
        mrk[a] = 1;
        dim(ar[a].fst);
        dim(ar[a].snd);
    }
    while(!ans.empty()){
        printf("%d\n", ans.top());
        ans.pop();
    }
}

