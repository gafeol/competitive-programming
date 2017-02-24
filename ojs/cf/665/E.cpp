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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

struct node{
	int l, r, cnt;
	node(int ll, int rr, int cc) {
		l = ll;
		r = rr;
		cnt = cc;
	}
	node(){
		l = -1;
		r = -1;
		cnt = 0;
	}
};

int n, m, k;
int s[MAXN], x[MAXN];

vector<node> v;

void add(int i, int val, int p){
	v[i].cnt++;
	if(p == -1) return;
	if((1<<p)&val){
		if(v[i].r == -1){
			v[i].r = v.size();
			v.pb(node(-1, -1, 0));
		}
		i = v[i].r;
	}
	else{
		if(v[i].l == -1){
			v[i].l = v.size();
			v.pb(node(-1, -1, 0));
		}
		i = v[i].l;
	}
	add(i, val, p-1);
}



ll qry(int i, int val, int p, int acu){
	if(i == -1) return 0;
	if(acu >= k) {
		return v[i].cnt; 
	}
	if(p == -1) return 0;
	if(acu + (1<<(p+1))-1 < k) return 0;

	return qry(v[i].l, val, p-1, acu|((1<<p)&val)) +
		qry(v[i].r, val, p-1, acu|((1<<p)^((1<<p)&val)));
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(a != 0) 
			x[a] = x[a-1];
		x[a] ^= s[a];
	}
	v.pb(node(-1, -1, 0));
	add(0, 0, 30);
	ll res = 0;
	for(int a=0;a<n;a++){
		res += qry(0, x[a], 30, 0); 
		add(0, x[a], 30);
	}
	printf("%lld\n", res);
}
