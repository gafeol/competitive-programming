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
const int MAXE = 2123456;

int n, m, k;
int s[MAXN];

vector<pii> adj[MAXN];
int cnt;

int mrk[MAXE];

int temp_path[MAXE], final_path[MAXE], tsz, fsz;


// so usar se garantido que tem euler cycle
void euler_dfs(int u){
	temp_path[tsz++] = u;
	for(pii ar: adj[u]){
		int id = ar.snd;
		if(mrk[id]) continue;
		mrk[id] = 1;

		int v = ar.fst;
		euler_dfs(v);
	}
	final_path[fsz++] = temp_path[--tsz];
}

void test(int c){
	fsz = 0;
	tsz = 0;
	for(int a=1;a<=c;a++)
		adj[a].clear();
	memset(mrk, 0, sizeof(mrk));
	for(int a=1;a<=c;a++){
		for(int b=a+1;b<=c;b++){
			adj[a].pb(pii(b, cnt));	
			adj[b].pb(pii(a, cnt++));
		}
	}
	if(!(c&1)){
		for(int a=1;a<=c;a+=2){
			adj[a].pb(pii(a+1, cnt));
			adj[a+1].pb(pii(a, cnt++));
		}
	}

	euler_dfs(1);

	if(final_path[fsz-1] == final_path[0])
		fsz--;

	vector<int> ans;
	for(int i=0;i<fsz;i++){
		ans.pb(final_path[i]);
	}
	if((c&1) && ans.size() < n)
		ans.pb(ans[0]);
	while(ans.size() < n){
		for(int cc=1;cc<=3;cc++){
			if(cc != ans[0] && cc != ans.back()){
				ans.pb(cc);
				break;
			}
		}
	}
	if(ans.size() != n || ans[0] == ans.back()) return ;
	printf("%d\n", c);
	for(int u: ans)
		printf("%d ", u);
	puts("");
	exit(0);
}

int main (){
	freopen("achromatic.in", "r", stdin);
	freopen("achromatic.out", "w", stdout);

	scanf("%d", &n);

	if(n == 4){
		puts("2");
		puts("1 2 1 2");
		return 0;
	}

	int c = 3;
	while(1){
		int sz = (c*(c-1))/2 + ((c&1) ? 0 : c/2-1);
		if(sz > n)
			break;
		c++;
	}
	c--;
	
	for(int cc=c;cc>=3;cc--){
		test(cc);
	}
}

