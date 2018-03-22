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

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;

int bit[MAXN];

struct pti{
	int x, y, z;
} s[MAXN];

bool cmp(pti a, pti b){
	return a.x < b.x;
}

int qry(int i){
	i+=2;
	int ans = INF;
	while(i > 0){
		ans = min(ans, bit[i]);
		i -= (i&-i);
	}
	return ans;
}

void upd(int i, int val){
	i += 2;
	while(i < MAXN){
		bit[i] = min(bit[i], val);
		i += (i&-i);
	}
}

int main (){
	for_tests(t, tt){
		memset(bit, INF, sizeof(bit));
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d %d %d", &s[a].x, &s[a].y, &s[a].z);
		}
		sort(s, s+n, cmp);
		int res = 0;
		for(int a=0;a<n;a++){
			if(qry(s[a].y) > s[a].z)
				res++;
			upd(s[a].y, s[a].z);
		}
		printf("%d\n", res);
	}
}
