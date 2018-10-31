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

const int MAXN = (1<<22) +9, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];
vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mrk[MAXN];
stack<int> res;

int newbm(int bm, int i){
	bm = (bm|(1<<i))^(1<<i);
	int nbm = 0;
	for(int a=0;a<n;a++){
		if(!(bm&(1<<a))) continue;
		for(int nxt: adj[a]){
			nbm |= (1<<nxt);
		}
	}
	return nbm;
}

int befbm[MAXN];
int befi[MAXN];

void go(int bm){
	queue<int> q;
	q.push(bm);
	mrk[bm] = 0;
	while(!q.empty()){
		bm = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			int nbm = newbm(bm, i);
			if(mrk[nbm] == INF){
				mrk[nbm] = mrk[bm] + 1;
				q.push(nbm);
				befbm[nbm] = bm;
				befi[nbm] = i;
			}
		}

	}
}

void print(int bm){
	if(bm == (1<<n)-1) return ;
	res.push(befi[bm]);
	print(befbm[bm]);
}

int main (){
	while(scanf("%d%d", &n, &m) && n+m){
		for(int a=0;a<n;a++)
			adj[a].clear();
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		memset(mrk, INF, sizeof(mrk));
		go((1<<n)-1);
		if(mrk[0] >= INF)
			puts("Impossible");
		else{
			print(0);
			printf("%d: ", (int)res.size());
			while(!res.empty()){
				printf("%d%c", res.top(), " \n"[res.size() == 1]);
				res.pop();
			}
		}
	}
}

