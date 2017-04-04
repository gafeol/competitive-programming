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
pii s[MAXN];

int cross(pii a, pii b){
	return abs(a.x*b.y - a.y*b.x);
}

inline int ts(int i, int j){
	int ii = i - 1, jj = j + 1;
	while(i < j){
		int l = (i+j)/3;
		int r = ((i+j)*2)/3;
		if(area
	}
}

int main{
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d %d", &s[a].fst, &s[a].snd);
			s[a+n] = s[a];
		}
		for(int i=0;i<n;i++){
			for(int j = i+2;j < n;j++){
				int l = ts(i+1, j-1);
				int r = ts(j+1, i+n-1);
			}
		}
	}
}
