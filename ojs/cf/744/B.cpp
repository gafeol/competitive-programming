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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];
int res[MAXN], mrk[MAXN], tempo;
vector<pii> q[2];
vector<int> ask;


int main (){
	int stop = 0;
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		res[a] = INT_MAX;
	}
	q[0].pb(pii(1, n));
	int t = 0;
	tempo = 1;
	while(!q[t].empty()){
		for(pii i: q[t]){
			int m = (i.fst + i.snd)/2; 
			for(int a=i.fst;a<=m;a++){
				ask.pb(a);
				mrk[a] = tempo;
			}
		}
		printf("%d\n", (int)ask.size());
		fflush(stdout);
		for(int v: ask){
			printf("%d ", v);
			fflush(stdout);
		}

		for(int a=1;a<=n;a++){
			int v;
			scanf("%d", &v);
			if(mrk[a] == tempo) continue;
			res[a] = min(res[a], v);
		}
		tempo++;
		ask.clear();
		for(pii i: q[t]){
			int m = (i.fst + i.snd)/2; 
			for(int a=m+1;a<=i.snd;a++){
				ask.pb(a);
				mrk[a] = tempo;
			}
		}
		printf("%d\n", (int)ask.size());
		fflush(stdout);
		for(int v: ask){
			printf("%d ", v);
			fflush(stdout);
		}
		for(int a=1;a<=n;a++){
			int v;
			scanf("%d", &v);
			if(mrk[a] == tempo) continue;
			res[a] = min(res[a], v);
		}
		ask.clear();
		tempo++;

		for(pii i: q[t]){
			int m = (i.fst + i.snd)/2; 
			if(i.fst != m)
				q[t^1].pb(pii(i.fst, m));
			if(i.snd != m+1)
				q[t^1].pb(pii(m+1, i.snd));
		}
		q[t].clear();
		t ^=1;
	}
	printf("-1\n");
	fflush(stdout);
	for(int a=1;a<=n;a++){
		printf("%d ", res[a]);
		fflush(stdout);
	}
}
