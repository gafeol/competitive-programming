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
int deg;
int L[MAXN*18], R[MAXN*18], cnt[MAXN*18];

void add(int x){
	int u = 0;
	int i = 27;	
	while(i > -1){
		cnt[u]++;
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
}

void rmv(int x){
	int u = 0;
	int i = 27;	
	while(i > -1){
		cnt[u]--;
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
}

int qry(int x, int val){
	int u = 0;
	int i = 27;	
	int ans = 0;
	while(i > -1){
		if(((1<<i)&val) == 0){
			if((1<<i)&x == 0){
				if(R[u] != -1)
					ans += cnt[R[u]];
				if(L[u] != -1)
					u = L[u];
			}
			else{
				if(L[u] != -1)
					ans += cnt[L[u]];
				if(R[u] != -1)
					u = R[u];
			}
		}
		else{
			if((1<<i)&x == 0){
				if(L[u] != -1)
					ans += cnt[L[u]];
				if(R[u] != -1)
					u = R[u];
			}
			else{
				if(R[u] != -1)
					ans += cnt[R[u]];
				if(L[u] != -1)
					u = L[u];
			}
		}
		i--;			
	}
	return ans;
}

int main (){
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t, p;
		scanf("%d%d", &t, &p);
		if(t == 1)
			add(p);
		else if(t == 2)
			rmv(p);
		else{
			int l;
			scanf("%d", &l);
			printf("%d\n", qry(p, l));
		}
	}
}
