#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
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
pii s[MAXN];
map<pii, int>  mrk;
vector<pii> v;

pii operator-(const pii & l,const pii & r) {   
	return {l.fst-r.fst,l.snd-r.snd};
}

ll cross(pii a, pii b){
	return (ll)a.snd*b.fst - (ll)a.fst*b.snd;
}

ll area(int i, int c, int j){
	pii va = v[i]-v[c];
	pii vb = v[j]-v[c];

	return abs(cross(va, vb));
}


inline int ts(int i, int j){
	int ii = i - 1, jj = j + 1;
	while(j - i + 1 > 3){
		int l = i + (j - i + 1)/3;
		int r = j - (j - i + 1)/3;
		if(area(ii, l, jj) >= area(ii, r, jj))
			j = r;
		else 
			i = l;
	}
	int ir = i;
	for(int a=i+1;a<=j;a++){
		if(area(ii, ir, jj) < area(ii, a, jj))
			ir = a;
	}
	return ir;
}

pii cv[2][MAXN];
int deg[2];


bool convex(int i, int t){
	pii va = cv[t][deg[t]-2] - cv[t][deg[t]-1];
	pii vb = s[i] - cv[t][deg[t]-1];

	return (cross(va, vb) <= 0);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){	
		v.clear();
		mrk.clear();
		deg[0] = deg[1] = 0;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d %d", &s[a].fst, &s[a].snd);
		}
		sort(s, s+n);
		for(int a=0;a<n;a++){
			while(deg[0] > 1 && !convex(a, 0))
				deg[0]--;
			debug("upp bota (%d, %d) em %d\n", s[a].fst, s[a].snd, deg[0]);
			cv[0][deg[0]++] = s[a];
		}
		for(int a=n-1;a>=0;a--){
			while(deg[1] > 1 && !convex(a, 1))
				deg[1]--;
			debug("lwr bota (%d, %d) em %d\n", s[a].fst, s[a].snd, deg[1]);
			cv[1][deg[1]++] = s[a];
		}
		for(int a=0;a<deg[0];a++){
			v.pb(cv[0][a]);
			debug("upp cvx (%d, %d)\n", cv[0][a].fst, cv[0][a].snd);
			mrk[cv[0][a]] = 1;
		}
		for(int a=0;a<deg[1];a++){
			if(mrk.find(cv[1][a]) == mrk.end()){
				v.pb(cv[1][a]);
				debug("lwr cvx (%d, %d)\n", cv[1][a].fst, cv[1][a].snd);
				mrk[cv[1][a]] = 1;
			}
		}
		int tam = v.size();
		ll res = 0;
		if(tam < 3){
			puts("0");
			continue;
		}
		if(tam == 3){
			res = area(0, 1, 2);
			printf("%lld", res/2);
			if(res&1)
				printf(".5");
			putchar('\n');
			continue;
		}
		for(int i=0;i<tam;i++){
			v.pb(v[i]);
		}

		for(int i=0;i<tam;i++){
			for(int j = i+2;j < tam;j++){
				int l = ts(i+1, j-1);
				int r = ts(j+1, i+tam-1);
				res = max(res, area(i, l, j) + area(i, r, j));
			}
		}
		printf("%lld", res/2);
		if(res&1)
			printf(".5");
		putchar('\n');
	}
}
