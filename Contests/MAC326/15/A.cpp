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
int deg[MAXN];
int mrk[MAXN];

vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	int x, l;
	scanf("%d%d%d%d", &n, &m, &x, &l);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		deg[i]++;
		deg[j]++;
	}
	queue<int> q;
	q.push(l);
	mrk[l] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nxt: adj[u]){
			if(mrk[nxt]) continue;	
			deg[nxt]--;
			if(deg[nxt] <= adj[nxt].size()/2){
				mrk[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	if(mrk[x])
		puts("leave");
	else
		puts("stay");
}

