#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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
const ll INF = 500000000000000000LL;

int n, m, k, sig;
pii s[MAXN];
pii add[MAXN];
ll dp[MAXN][2][2][2][2];

template <typename T,typename U>
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
	return {l.first+r.first,l.second+r.second};                                    
}    
template <typename T,typename U>
pair<T,U> operator-(const pair<T,U> & l,const pair<T,U> & r) {   
	return {l.first-r.first,l.second-r.second};                                    
}
template <typename T,typename U>
pair<T,U> operator/(const pair<T,U> & l, const ll & r){
	return {l.fst/r, l.snd/r};
}


pii mv(int i, int mi){
	return (s[i]+add[mi])/2ll;
}

ll cross(pii A, pii B){
	return A.fst*B.snd - A.snd*B.fst;
}

ll ab(ll x){
	if(x < 0) return -x;
	return x;
}

ll area(int i, int mi, int j, int mj, int k, int mk){
	pii ii = mv(i, mi);
	pii jj = mv(j, mj);
	pii kk = mv(k, mk);

	pii A = ii - jj;
	pii B = kk - jj;

	return ab(cross(A, B));
}

bool valid(int i, int mi, int j, int mj, int k, int mk){
	pii ii = mv(i, mi);
	pii jj = mv(j, mj);
	pii kk = mv(k, mk);

	pii A = ii - jj;
	pii B = kk - jj;
	if(sig)
		return cross(A, B) < 0;
	else
		return cross(A, B) > 0;
}

ll go(int i, int u, int v, int pri, int seg){
	if(dp[i][u][v][pri][seg] != -1){
		return dp[i][u][v][pri][seg];
	}

	ll &r = dp[i][u][v][pri][seg];
	r = INF;

	if(i == n)
		return r = (valid(n-2, u, n-1, v, 0, pri) && valid(n-1, v, 0, pri, 1, seg) ? 0:INF);

	for(int a=0;a<2;a++){
		if(valid(i-2, u, i-1, v, i, a))
			r = min(r, go(i+1, v, a, pri, seg) + area(i-1, v, 0, pri, i, a));
	}
	return r;
}

int main (){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a].fst, &s[a].snd);
		s[a].fst *= 2ll;
		s[a].snd *= 2ll;
	}
	for(int i=0;i<2;i++){
		scanf("%lld %lld", &add[i].fst, &add[i].snd);
		add[i].fst *= 2ll;
		add[i].snd *= 2ll;
	}
	ll res = INF;
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			res = min(res, go(2, a, b, a, b));
		}
	}
	sig = 1;
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			res = min(res, go(2, a, b, a, b));
		}
	}
	printf("%.3f\n", .125*res);
}
