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

const int MAXN = 100005;

int n, m, k;
int s[MAXN];
int deg;
int L[MAXN*30], R[MAXN*30], cnt[MAXN*30];

void upd(int x, int val){
	int u = 0;
	int i = 27;	
	while(i > -1){
		cnt[u]+=val;
		debug("upd %d val %d cnt[u] %d\n", u, val, cnt[u]);
		if(((1<<i)&x) == 0){
			if(L[u] == -1)
				L[u] = deg++;
			u = L[u];
		}
		else{
			if(R[u] == -1)
				R[u] = deg++;
			u = R[u];
		}
		i--;			
	}
	debug("upd %d val %d cnt[u] %d\n", u, val, cnt[u]+val);
	cnt[u] += val;
}

int qry(int x, int val){
	int u = 0;
	int i = 27;	
	int ans = 0;
	while(i > -1){
		debug("qry %d  i %d bit %d\n", u, i, (1<<i));

		if(((1<<i)&val) == 0){
			if(((1<<i)&x) == 0){
				if(L[u] != -1)
					u = L[u];
				else
					return ans;
			}
			else{
				if(R[u] != -1)
					u = R[u];
				else
					return ans;
			}
		}
		else{
			if(((1<<i)&x) == 0){
				if(L[u] != -1)
					ans += cnt[L[u]];
				if(R[u] != -1)
					u = R[u];
				else
					return ans;
			}
			else{
				if(R[u] != -1)
					ans += cnt[R[u]];
				if(L[u] != -1)
					u = L[u];
				else
					return ans;
			}
		}
		i--;			
	}
	return ans;
}

int main (){
	deg = 1;
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t, p;
		scanf("%d%d", &t, &p);
		if(t == 1)
			upd(p, 1);
		else if(t == 2)
			upd(p, -1);
		else{
			int l;
			scanf("%d", &l);
			printf("%d\n", qry(p, l));
		}
	}
}

