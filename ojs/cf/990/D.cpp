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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;

int n, m, k;
int s[MAXN];

int mrk[MAXN];
int mrki[MAXN];

int M[MAXN][MAXN];

vector<int> adj[MAXN];
vector<int> inv[MAXN];

int A, B;

void add(int i, int j){
	M[i][j] = 1;
	M[j][i] = 1;
	adj[i].pb(j);
	adj[j].pb(i);
}

void go(int u){
	mrk[u] = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);
	}
}
void gi(int u){
	mrki[u] = 1;
	for(int nxt: inv[u]){
		if(mrki[nxt]) continue;
		gi(nxt);
	}
}

bool check(int t, int A, int B, int i, int j){
	if(t)
		return (A == i && B == j);
	return (A == j && B == i); 
}

int main (){
	scanf("%d%d%d", &n, &A, &B);
	if(A != 1 && B != 1){
		puts("NO");
		return 0;
	}
	int t;
	t = (B == 1);
	int cnt = max(A, B);
	for(int a=1;a<=n - cnt;a++){
		add(a-1, a);	
	}
	for(int a=0;a<n;a++)
	{
		for(int b=a+1;b<n;b++){
			if(!M[a][b]){
				inv[b].pb(a);
				inv[a].pb(b);
			}
		}
	}
	int comp = 0;
	for(int a=0;a<n;a++){
		if(!mrk[a]){
			comp++;
			go(a);
		}
	}
	int comp2 = 0;
	for(int a=0;a<n;a++){
		if(!mrki[a]){
			comp2++;
			gi(a);
		}
	}
	debug("comp %d comp2 %d\n", comp, comp2);
	if(!check(t, A, B, comp, comp2)){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(a == b){
				printf("0");
				continue;
			}
			printf("%d", (M[a][b] == t));
		}
		puts("");
	}
}
