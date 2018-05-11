#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int charat[30][400];

string w[MAXN];

unordered_map<int, unordered_map<char, int> > adj;
int deg;

int main (){
	for_tests(t, tt){
		deg = 1;
		ans.clear();
		adj.clear();
		debug("sz all %d\n", (int)adj.size());
		debug("sz %d\n", (int)adj[0].size());
		scanf("%d%d", &n, &m);
		for(int a=0;a<=m;a++)
			for(int b='A';b<='Z';b++)
				charat[a][b] = 0;

		for(int a=0;a<n;a++){
			char c;
			cin >> w[a];
			for(int b=0;b<m;b++){
				charat[b][w[a][b]] = 1+a;
			}
		}
		for(int a=n-1;a>=0;a--)
			add(a);

		printf("Case #%d: ", tt);
		if(qry(0, 0)){
			for(char c: ans)
				printf("%c", c);
			puts("");
		}
		else{
			puts("-");
		}
	}
}

