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
int p[MAXN], pai[MAXN], sz[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<tuple<char, int, int> > qry;

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int u, int v){
	if(v == 0) return ;
	u = raiz(u);
	v = raiz(v);
	if(u == v) return ;

	if(sz[u] < sz[v])
		swap(u, v);
	
	pai[v] = u;
	sz[u] += sz[v];
}

int mrk[MAXN];

int main (){
	for_tests(t, tt){
		qry.clear();
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n;a++){
			scanf("%d", p+a);
			pai[a] = a;
			sz[a] = 1;
			mrk[a] = 0;
		}
		for(int a=0;a<m;a++){
			char c;
			int x, y;
			scanf(" %c %d", &c, &x);
			if(c == 'Q')
				scanf("%d", &y);
			else{
				if(mrk[x]) 
					continue;
				mrk[x] = 1;
			}
			qry.pb({c, x, y});
		}
		for(int a=1;a<=n;a++){
			if(!mrk[a])
				join(a, p[a]);
		}
		stack<string> ans;
		printf("Case #%d:\n", tt);
		for(int a=qry.size()-1;a>=0;a--){
			char c;
			int x, y;
			tie(c, x, y) = qry[a];
			if(c == 'Q'){
				if(raiz(x) == raiz(y))
					ans.push("YES");
				else
					ans.push("NO");
			}
			else
				join(x, p[x]);
		}
		while(!ans.empty()){
			cout << ans.top() << endl;
			ans.pop();
		}
	}
}

