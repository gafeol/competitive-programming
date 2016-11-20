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

int n, m, k, ns, l;
int s[MAXN], bef[MAXN], aft[MAXN], mrk[MAXN];

int dist(int a, int b){
	return b - a + 1;
}
vector<int> res;

int main (){
	scanf("%d%d%d%d", &n, &ns, &l, &m);
	// MAS E SE NS == NUMERO ESPACOS
	s[0] = 1;
	s[n+1] = 1;
	bef[0] = 0;
	aft[n+1] = n+1;
	int ne = 0;
	for(int a=1;a<=n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = (c == '1');
		if(s[a]) bef[a] = a;
		else bef[a] = bef[a-1];
	}
	for(int a=n;a>=1;a--){
		if(s[a]) aft[a] = a;
		else aft[a] = aft[a+1];
	}
	for(int a=1;a<=n;a++){
		if(s[a]) continue;
		ne += (dist(bef[a]+1, aft[a]-1)/l);
		a = aft[a];
	}
	for(int a=1;a<=n;a++){
		if(ne < ns) continue;
		if(s[a]) continue;
		bef[a] = bef[a-1];
		if(dist(bef[a]+1, aft[a]-1) < l)
			continue;
		if(dist(bef[a]+1, a) < l)
			continue;
		if(res.size() > 0 && dist(res[res.size()-1], aft[a]-1) <= l){
		//	debug("puleidson %d\n", a);
			continue;
		}
		if(res.size()>0 && dist(res[res.size()-1], a) <= l ) continue;
		res.pb(a);
		ne -= dist(bef[a]+1, aft[a]-1)/l;
		bef[a] = a;
		ne += dist(bef[a]+1, aft[a]-1)/l;	
		debug("afte shot left %d\n", ne);
	}
	printf("%d\n", (int)res.size());
	for(int i: res){
		printf("%d ", i);
	}
}
