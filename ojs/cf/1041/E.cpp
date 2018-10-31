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
pii s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii ar[MAXN];

void fail(){
    puts("NO");
    exit(0);
}

map<pii, int> cnt, cc;

set<int> v;

vector<pii> res;
vector<int> adj[MAXN];

int mx[3];

void go(int u, int p, int t){
    mx[t] = max(mx[t], u);
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        go(nxt, u, t);
    }
}

int main (){
	scanf("%d", &n);
    for(int a=1;a<=n;a++)
        v.insert(a);
	for(int a=0;a<n-1;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        if(i > j) swap(i, j);
        if(j != n)
            fail();
        s[a] = pii(i, j);
        if(v.find(i) != v.end())
            v.erase(i);
        if(v.find(j) != v.end())
            v.erase(j);
        cnt[s[a]]++;
        cc[s[a]]++;
	}
    for(int a=0;a<n-1;a++){
        if(cnt[s[a]] == 0) continue;                
        int ult = s[a].fst;
        int qtd = cnt[s[a]];
        while(qtd > 1){
            if(v.empty() || v.lower_bound(s[a].fst) == v.begin())
                fail();
            int mid = *(--v.lower_bound(ult)); 
            v.erase(mid);
            res.pb(pii(ult, mid));
            adj[ult].pb(mid);
            adj[mid].pb(ult);
            ult = mid;
            qtd--;
        }
        res.pb(pii(ult, s[a].snd));
        adj[ult].pb(s[a].snd);
        adj[s[a].snd].pb(ult);
        cnt[s[a]] = 0;
    }

    for(int a=0;a<n-1;a++){
        mx[1] = mx[0] = INT_MIN;
        go(res[a].fst, res[a].snd, 0);
        go(res[a].snd, res[a].fst, 1);
        int i = mx[0], j = mx[1];
        if(i > j) swap(i, j);
        cc[pii(i, j)]--;
        if(cc[pii(i, j)] < 0)
            fail();
    }

    puts("YES");
    for(pii x: res){
        printf("%d %d\n", x.fst, x.snd);
    }
}

