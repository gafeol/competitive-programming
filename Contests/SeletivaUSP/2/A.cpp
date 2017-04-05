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

int area(int i, int c, int j){
	pii va = s[i]-s[c];
	pii vb = s[j]-s[c];

	return cross(va, vb);
}

inline int ts(int i, int j){
	int ii = i - 1, jj = j + 1;
	while(j - i + 1 > 2){
		int l = i + (j - i + 1)/3;
		int r = j - (j - i + 1)/3;
		if(area(ii, l, jj) >= area(ii, r, jj))
			j = r;
		else 
			i = l;
	}
	if(area(ii, i, jj) < area(ii, j, jj))
		swap(i, j);
	return i;
}

int deg;

pii cv[MAXN];

bool convex(int i){
	if(cross(cv[deg-2], cv[deg-1], s[i] >= 0);
}

int main{
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d %d", &s[a].fst, &s[a].snd);
		}
		sort(s, s+n);
		cv[deg++] = s[0];
		cv[deg++] = s[1];
		for(int a=2;a<n;a++){
			while(deg > 2 && !convex(a))
				deg--;

			if(convex(a))
				cv[deg++] = a;
		}
		for(int i=0;i<n;i++){
			for(int j = i+2;j < n;j++){
				int l = ts(i+1, j-1);
				int r = ts(j+1, i+n-1);
			}
		}
	}
}
