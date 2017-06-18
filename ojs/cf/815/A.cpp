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

const int MAXN = 212;

int n, m, k;
int s[MAXN];
int M[MAXN][MAXN];

vector<pii> r;

void  upd(int t, int i, int val){
	if(t){
		for(int a=0;a<n;a++){
			M[a][i] -= val;
		}
	}
	else
		for(int b=0;b<m;b++){
			M[i][b] -= val;
		}
}

int main (){
	scanf("%d%d", &n, &m);
	int som = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d", &M[a][b]);
			som += M[a][b];
		}
	}
	int res =0;
	while(som){
		int t, i = -1, cnt=0;
		for(int a=0;a<n;a++){
			int mn = INT_MAX;
			for(int b=0;b<m;b++){
				mn = min(mn, M[a][b]);
			}
			if(mn > 0 && m > cnt){
				i = a;
				t = 0;
				cnt = m;
			}
		}
		for(int b=0;b<m;b++){
			int mn = INT_MAX;
			for(int a=0;a<n;a++){
				mn = min(mn, M[a][b]);
			}
			if(mn > 0 && n > cnt){
				i = b;
				t = 1;
				cnt = n;
			}
		}
		if(cnt == 0) break;
		res++;
		upd(t, i, 1);
		som -= cnt;
		r.pb(pii(t, i+1));
	}
	if(som != 0)
		puts("-1");
	else{
		printf("%d\n", res);
		for(pii u: r){
			if(u.fst == 0)
				printf("row ");
			else
				printf("col ");
			printf("%d\n", u.snd);
		}
	}
}
