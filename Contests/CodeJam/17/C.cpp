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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN], mrk[MAXN];

queue<pii> q;

int L[MAXN], R[MAXN];

int main (){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		scanf("%d%d", &n, &k);	
		int cnt = 0;
		int resmn, resmx;
		int mn, mx;
		R[n+1] = -1;
		L[0] = -1;
		while(cnt != k){
			for(int a=1;a<=n;a++){
				L[a] = L[a-1] + 1;
				if(mrk[a])
					L[a] = -1;
			}
			for(int a=n;a>=0;a--){
				R[a] = R[a+1] + 1;
				if(mrk[a])
					R[a] = -1;
			}
			int mx, mn = INT_MIN, i;
			for(int a=1;a<=n;a++){
				if(min(L[a], R[a]) > mn){
					mn = min(L[a], R[a]);
					mx = max(L[a], R[a]);
					i = a;
				}
				else if(mn == min(L[a], R[a]) && mx < max(L[a], R[a])){
					mn = min(L[a], R[a]);
					mx = max(L[a], R[a]);
					i = a;
				}
			}
			mrk[i] = 1;
			resmn = min(L[i], R[i]);
			resmx = max(L[i], R[i]);
			cnt++;
		}
		printf("Case #%d: %d %d\n", tt, resmx, resmn);
	}
}
