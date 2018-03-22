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

const int MAXN = 300005;
const int MAXT = 300005*31;

int n, m, k;
int s[MAXN];

int l[MAXT], r[MAXT];
int deg;
int cnt[MAXT];

void add(int x){
	int u = 0;
	for(int i=30;i>=0;i--){
		if(!(x&(1<<i))){

			if(l[u] == -1)
				l[u] = deg++;
			u = l[u];
		}
		else{
			if(r[u] == -1)
				r[u] = deg++;
			u = r[u];
		}
		cnt[u]++;
	}
}

ll go(ll x){
	int u = 0;
	ll ans = 0;
	for(int i=30;i>=0;i--){
		if(!(x&(1<<i))){
			if(l[u] == -1 || cnt[l[u]] == 0){
				ans += (1<<i);
				u = r[u];
			}
			else
				u = l[u];
		}
		else{
			if(r[u] == -1 || cnt[r[u]] == 0){
				ans += (1<<i);
				u = l[u];
			}
			else
				u = r[u];
		}
		cnt[u]--;
	}
	return ans;
}


int main (){
	deg = 1;
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		add(x);
	}
	for(int a=0;a<n;a++){
		printf("%lld ", go(s[a]));
	}
	puts("");
}

