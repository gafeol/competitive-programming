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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

vector<int> adj[MAXN];
int deg[MAXN];
int M[MAXN][MAXN];
int ind[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
	scanf("%d", &n);
	for(int a=0;a<=n;a++)
		ind[a] = a;
	for(int a=0;a<n-1;a++){
		for(int b=0;b<=a;b++){
			scanf("%d", &M[a][b]);
		}
	}
	for(int b=0;b<n-1;b++){
		for(int a=n-2;a>=b;a--){
			/*
			printf("a %d b %d\n", a, b);
			printf("ind: ");
			for(int a=0;a<n;a++)
				printf("%d ", ind[a]);
			puts("");
			*/
			if(M[a][b]){
				//printf("M[%d][%d] %d\n", a, b, M[a][b]);
				adj[ind[a]].pb(ind[a+1]);
				//printf("liga %d -> %d\n", ind[a], ind[a+1]);
				deg[ind[a+1]]++;
				swap(ind[a+1], ind[a]);
			}
			else{
				adj[ind[a+1]].pb(ind[a]);
				//printf("liga %d -> %d\n", ind[a+1], ind[a]);
				deg[ind[a]]++;
			}
		}
	}
	queue<int> q;
	for(int a=0;a<n;a++){
		if(!deg[a]){
			q.push(a);
		}
	}
	int cnt = n;
	int res[MAXN];
	while(!q.empty()){
		int u = q.front();
		q.pop();
		res[u] = cnt--;
		//fprintf(stderr, "res %d = %d\n", u, res[u]);
		for(int nxt: adj[u]){
			deg[nxt]--;
			if(!deg[nxt])
				q.push(nxt);
		}
	}
	if(cnt){
		puts("NO");
	}
	else{
		puts("YES");
		for(int a=0;a<n;a++)
			printf("%d%c", res[a], " \n"[a==n-1]);
	}
}

