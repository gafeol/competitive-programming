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
const int inf = 300000000;

int n, m, k;
char s[30];
int inv[30];

int ch[30][30];
int cs[30][30];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct pd{
	int x[30];
	bool ok;

	pd(){
		ok = 0;
		for(int a=0;a<30;a++)
			x[a] = inf;
	}

	pd operator * (pd o) const {
		pd res;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				int c = ch[a][b];
				int cus = cs[a][b];
				res.x[c] = min(res.x[c], cus + x[a] + o.x[b]);
			}
		}
		res.ok = 1;
		return res;
	}

} dp[MAXN][MAXN];

int pc[MAXN];


pd go(int i, int j){
	//printf("go %d %d\n", i, j);
	if(dp[i][j].ok)
		return dp[i][j];
	dp[i][j].ok = 1;

	if(i == j){
		//printf("pc %d\n", pc[i]);
		dp[i][j].x[pc[i]] = 0;
		return dp[i][j];
	}
	for(int m=i;m<j;m++){
		//printf("aux %d %d * %d %d\n", i, m, m+1, j);
		pd a = go(i, m);
		pd b = go(m+1, j);
		pd aux = (go(i, m)*go(m+1, j)); 	
		for(int a=0;a<n;a++){
			//printf("volta pra %d %d (%d): %d\n", i, j, a, aux.x[a]);
			dp[i][j].x[a] = min(dp[i][j].x[a], aux.x[a]);
		}
	}
	return dp[i][j];
}

void zera(int tam){
	for(int a=0;a<tam;a++){
		for(int b=0;b<tam;b++){
			dp[a][b].ok = 0;
			for(int c=0;c<n;c++){
				dp[a][b].x[c] = inf;
			}
		}
	}
}

int main (){
	bool f = 1;
	while(scanf("%d", &n) && n){
		if(!f)
			puts("");
		f = 0;
		for(int a=0;a<n;a++){
			char c;
			scanf(" %c", &c);
			s[a] = c;
			inv[c-'a'] = a;
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				int cus;
				char c;
				scanf("%d-%c", &cus, &c);
				int ic = inv[c-'a'];								
				ch[a][b] = ic;
				cs[a][b] = cus;
			}
		}
		scanf("%d", &m);
		char pal[300];
		pii res = pii(-1, 0);
		for(int a=0;a<m;a++){
			scanf(" %s", pal);
			int tam = strlen(pal);	
			for(int a=0;a<tam;a++)
				pc[a] = inv[pal[a]-'a']; 
			zera(tam);
			pd ans = go(0, tam-1);
			int res = inf;
			for(int a=0;a<n;a++)
				res = min(ans.x[a], res);
			printf("%d-", res); for(int a=0;a<n;a++){
				if(res == ans.x[a]){
					printf("%c\n", s[a]);
					break;
				}
			}
		}
	}
}

