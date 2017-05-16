#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

const int MAXN = 212, INF = 0x3f3f3f3f;

int n, m;
int s[MAXN];
int d[MAXN];

vector<ppi> ares;

ppi mk(int a, int b, int c){
	return ppi(pii(a, b), c);
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		scanf("%d",&m);
		for(int a=0;a<m;a++){
			char c[3];
			int i, j, nn, k;
			scanf("%d %d %s %d", &i, &nn, c, &k);
			j = i + nn;
			i--;
			if(c[0] == 'g')
				ares.pb(mk(j, i, -k-1));
			else
				ares.pb(mk(i, j, k-1));
		}
		memset(d, INF, sizeof(d));
		d[0] = 0;	
		for(int it=0;it<2*n;it++){
			for(ppi ar: ares){
				int i = ar.fst.fst;
				int j = ar.fst.snd;
				int k = ar.snd;
				if(d[j] > d[i] + k)
					d[j] = d[i] + k;
			}
		}

		//checking negative cycle
		bool has = false;
		for(ppi ar: ares){
			int i = ar.fst.fst;
			int j = ar.fst.snd;
			int k = ar.snd;
			if(d[j] > d[i] + k){
				d[j] = d[i] + k;
				has = true;
			}
		}
		ares.clear();
		if(has)
			printf("successful conspiracy\n");
		else
			printf("lamentable kingdom\n");
		
	}
}
