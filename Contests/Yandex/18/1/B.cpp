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

int nxt[MAXN][10];

int pos[MAXN];

char st[MAXN];

vector<char> v;

int main (){
	scanf(" %s", st);
	n = strlen(st);
	for(int a=0;a<n;a++){
		s[a] = st[a]-'0';
	}
	for(int a=0;a<10;a++){
		nxt[n][a] = n;
		nxt[n+1][a] = n;
	}
	for(int a=n-1;a>=0;a--){
		for(int d=0;d<10;d++)
			nxt[a][d] = nxt[a+1][d];
		nxt[a][s[a]] = a;
	}
	for(char c = 'a';c <='j';c++)
		v.pb(c);
	int res = 0;
	do{
		int u = 0;
		for(int a=0;a<v.size();a++)
			pos[v[a]] = a;
		for(int a='a';a<='j';a++)
			u = nxt[u][pos[a]]+1;
		if(u <= n)
			res++;
	} while(next_permutation(v.begin(), v.end()));
	printf("%d\n", res);
}

