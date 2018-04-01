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

const int MAXN = 145;

int n, m, k;
int s[MAXN];

int mrkc[MAXN], mrkl[MAXN];
char M[MAXN][MAXN], aux[MAXN][MAXN];

int main (){
	int ok = 1;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int a=0;a<n;a++){
		int ini = 0;
		vector<int> col;
		for(int b=0;b<m;b++){
			if(M[a][b] == '#'){
				col.pb(b);
			}
		}
		for(int b = 1;b<col.size();b++){
			for(int aa=0;aa<n;aa++){
				if(M[aa][col[b]] != M[aa][col[b-1]]){
					ok = 0;
				}
			}
		}
		col.clear();

	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			aux[b][a] = M[a][b];
		}
	}
	swap(n, m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			M[a][b] = aux[a][b];
		}
	}
	for(int a=0;a<n;a++){
		int ini = 0;
		vector<int> col;
		for(int b=0;b<m;b++){
			if(M[a][b] == '#'){
				col.pb(b);
			}
		}
		for(int b = 1;b<col.size();b++){
			for(int aa=0;aa<n;aa++){
				if(M[aa][col[b]] != M[aa][col[b-1]])
					ok = 0;
			}
		}
		col.clear();
	}
	if(ok)
		puts("Yes");
	else
		puts("No");
}

