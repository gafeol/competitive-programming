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

const int MAXN = 2001;

int n, m, k;
pii s[MAXN];

unordered_map<el, int> dp[MAXN][9];

struct el{
	int f[4];
	el(){}

	void ord(){
		for(int i=0;i<4;i++)
			for(int j=i;j<4;j++)
				if(f[i] < f[j])
					swap(f[i], f[j]);
	}

	el(int a, int b, int c, int d){
		f[0] = a;
		f[1] = b;
		f[2] = c;
		f[3] = d;
		ord();
	}
	
	int empty(){
		return (f[0] == 0);
	}

	int full(){
		return (f[3] != 0);
	}

	el add(int x){
		for(int a=0;a<4;a++){
			if(f[a] == 0){
				f[a] = x;
				return this;
			}
		}
	}
	el rmv(int x){
		for(int a=0;a<4;a++){
			if(f[a] == x){
				f[a] = 0;
			}
		}
		ord();
		return this;
	}
	int qtd(int x){
		int cnt = 0;
		for(int a=0;a<4;a++)
			if(f[a] == x)
				cnt++;
		return cnt;
	}
}


int go(int i, int fl, el e){
	int &r = dp[i][t][e];	
	if(r != -1) return r;
	r = INT_MAX;
	
	if(i == n && e.empty()) return r = 0;

	if(!e.full())
		r = min(r, abs(fl - s[i].fst) + el.qtd(s[i].fst) + go(i+1, s[i].fst, e.remove(s[i].fst).add(s[i].snd)));
	for(int a=0;a<4;a++){
		if(r.f[a] != 0)
			r = min(r, abs(fl - r.f[a]))
	}
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
	}
	s[0] = pii(1, 1);
	go(0, 1, el(0, 0, 0, 0));
}

