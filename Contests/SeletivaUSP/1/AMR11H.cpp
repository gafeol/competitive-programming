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
inline ll mod(ll x) { 
	while(x < 0)
		x += modn;
	return x % modn; 
}

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
int pos[2];
ll res[2];
int v[2];
int cnt[2];
ll dois[MAXN];

int main (){
	dois[0] = 1;
	for(int a=1;a<MAXN;a++){
		dois[a] = mod(2*dois[a-1]);
	}
	for_tests(t, tt){
		res[0] = res[1] = 0;
		cnt[0] = cnt[1] = 0;
		scanf("%d", &n);

		v[0] = INT_MAX;
		v[1] = INT_MIN;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			v[1] = max(v[1], s[a]);
			v[0] = min(v[0], s[a]);
		}
		if(v[0] == v[1]){
			for(int i=0;i<n;i++){
				res[0] = mod(res[0] + n-i); 
			}
			res[1] = dois[n] - 1; 
			printf("%lld %lld\n", res[0], res[1]);
			continue;
		}
		pos[0] = -1;
		pos[1] = -1;
		for(int i=0;i<n;i++){
			for(int a=0;a<2;a++){
				if(s[i] == v[a]){
					cnt[a]++;
					pos[a] = i;
				}
			}
			res[0] = mod(res[0] + min(pos[0], pos[1])+1);
		}
		res[1] = mod(dois[n] - dois[n - cnt[0]] - dois[n - cnt[1]] + dois[n - cnt[1] - cnt[0]]);
		printf("%lld %lld\n", res[0], res[1]);
	}
}
