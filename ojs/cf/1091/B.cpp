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
pii s[MAXN], h[MAXN];

map<pii, int> cnt, o;

bool test(int x, int y){
	for(int a=0;a<n;a++){
		pii np = pii(x - s[a].fst, y - s[a].snd);
		if(cnt[np] > 0){
			cnt[np]--;
		}
		else
			return false;
	}
	return true;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d%d", &s[a].fst, &s[a].snd);
	for(int a=0;a<n;a++){
		scanf("%d%d", &h[a].fst, &h[a].snd);
		o[h[a]]++;
	}
	vector<pii> pos(n);
	for(int a=0;a<n;a++){
		pos[a] = pii(s[0].fst + h[a].fst, s[0].snd + h[a].snd);
	}

	for(pii p: pos){
		cnt = o;
		if(test(p.fst, p.snd)){
			printf("%d %d\n", p.fst, p.snd);
			return 0;
		}
	}
}

