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
int p[MAXN], p2[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		scanf("%d", s+a);
	}
	vector<int> v;
	int deg = 1;
	v.pb(0);
	int ok = 1;
	for(int a=0;a<=n;a++){
		int degg = deg;
		int cnt = s[a];
		while(cnt--){
			p2[degg] = v.front();
			p[degg] = v.front();
			degg++;
		}
		if(s[a] > 1 && v.size() > 1 && ok){
			ok = 0;
			p2[degg-1] = v.back();
		}
		v.clear();
		while(s[a]--){
			v.pb(deg);
			deg++;
		}
	}
	if(ok)
		puts("perfect");
	else{
		puts("ambiguous");
		for(int a=1;a<deg;a++)
			printf("%d ", p[a]);
		puts("");
		for(int a=1;a<deg;a++)
			printf("%d ", p2[a]);
		puts("");
	}
}

