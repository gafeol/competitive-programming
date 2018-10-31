#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)

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
int p[MAXN];

map<string, int> ind;
int cnt;

ll hasa[MAXN], hasd[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> fol;

vector<int> adj[MAXN];

vector<int> vh[MAXN];
int h[MAXN];

ll allmn[MAXN], allmx[MAXN], dmn[MAXN], dmx[MAXN];

void dfs(int u, int p){
	h[u] = h[p] + 1;
	vh[h[u]].pb(u);
	for(int nxt: adj[u]){
		dfs(nxt, u);
	}
	if(adj[u].empty()){
		hasa[u] = max(hasa[u], hasd[u]);
		hasd[u] = max(hasa[u], hasd[u]);
	}
}

ll sumallmn[MAXN];

main (){
	clock_t clk = clock();
	scanf("%lld%lld", &n, &m);
	cnt = 1;
	for(int a=0;a<n;a++){
		int d, al;
		char f[MAXN], p[MAXN];
		scanf(" %s %s %lld %lld", f, p, &d, &al);
		int indp, indf;
		if(strcmp(p, "NONE") == 0){
			indp = 0;
		}
		else{
			if(ind.find(p) == ind.end())
				ind[p] = cnt++;
			indp = ind[p];
		}
		if(ind.find(f) == ind.end())
			ind[f] = cnt++;
		indf = ind[f];

		::p[indf] = indp;
		adj[indp].pb(indf);
		hasa[indf] = al;
		hasd[indf] = d;
	}
	dfs(1, 0);

	while(((double)clock() - clk)/CLOCKS_PER_SEC < 3.0){

		for(int a=n+1;a>=0;a--){
			for(int u: vh[a]){
				bool kd = hasd[u];
				bool ha = 1;
				ll suma = 0;
				for(int nxt: adj[u]){
					ha = min(ha, (bool)hasa[nxt]);
					suma += hasa[nxt];
				}
				if(kd && ha)
					hasa[u] = suma + hasd[u];	
				if(ha && hasa[u])
					hasd[u] = hasa[u] - suma;
			}
		}

		for(int a=0;a<=n+1;a++){
			for(int u: vh[a]){
				int ind=-1, cnt = (hasa[u] == 0);
				ll suma = 0;
				for(int nxt: adj[u]){
					suma += hasa[nxt];
					if(!hasa[nxt]){
						ind = nxt;
						cnt++;
					}
				}
				if(cnt == 0){
					hasd[u] = hasa[u] - suma;
				}
				if(cnt == 1 && ind != -1 && hasd[u]){
					hasa[ind] = hasa[u] - hasd[u] - suma;
				}
			}
		}


		for(int a=n+1;a>=0;a--){
			for(int u: vh[a]){
				ll samn = 0;
				for(int nxt: adj[u]){
					samn += allmn[nxt];
				}
				sumallmn[u] = samn;
				allmn[u] = max(1ll, max(dmn[u], hasd[u])) + samn;

				if(hasd[u])
					allmn[u] = max(allmn[u], hasd[u]);
				if(hasa[u])
					allmn[u] = hasa[u];
			}
		}

		allmx[0] = 6000000001LL;
		sumallmn[0] = allmn[1];

		for(int a=0;a<=n+1;a++){
			for(int u: vh[a]){
				int pai = p[u];			
				allmx[u] = allmx[pai] - sumallmn[pai] + allmn[u] - max(1ll, max(dmn[pai], hasd[pai])); // tratar allmx[0]
				if(hasa[u])
					allmx[u] = hasa[u];
			}
		}
		for(int a=n+1;a>=0;a--){
			for(int u: vh[a]){
				int pai = p[u];
				dmx[u] = allmx[u] - sumallmn[u];
				if(hasd[u])
					dmx[u] = hasd[u];
				ll samx = 0;
				for(int nxt: adj[u]){
					samx += allmx[nxt];
				}
				dmn[u] = max(1ll, allmn[u] - samx);
				if(hasd[u])
					dmn[u] = hasd[u];
			}
		}
	}

	//for(int a=1;a<cnt;a++){
		//printf("A %d\n", a);
		//printf("all %lld %lld\n", allmn[a], allmx[a]);
		//printf("d %lld %lld\n", dmn[a], dmx[a]);
	//}

	for(int a=0;a<m;a++){
		char s[MAXN];
		int t;
		scanf(" %s %lld", s, &t);
		int id = ind[s];
		if(t == 1){
			printf("%lld %lld\n", dmn[id], max(dmn[id], dmx[id]));
		}
		else
			printf("%lld %lld\n", allmn[id], max(allmn[id], allmx[id]));
	}
}

