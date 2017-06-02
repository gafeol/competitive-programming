#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pii, int> ppi;
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
ll s[MAXN][2];
ll d;

map<int, vector<ppi> > ind;

void fail(){
	puts("impossible");
	exit(0);
}

pii transf(ll x, ll y){
	pll aux = pii(x, y);
	aux.fst = p.fst + p.snd;
	aux.snd = p.snd - p.fst;
	return aux; 
}

void add(ll x, ll y){
	pii ini;
	int xx = transf(x-d, y)
}

int main(){
		scanf("%d %d", &s[a][0], &s[a][1]);
		tl += s[a][0];
		tr += s[a][1];
	}
	if(tl < tr){
		swap(tl, tr);
		for(int a=0;a<n;a++){
			swap(s[a][0], s[a][1]);
		}
	}
	int res;
	int ir = -1;
	if(tl == tr){
		res = 0;
		for(int a=0;a<n;a++){
			if(res < s[a][0] + s[a][1]){
				res = s[a][0] + s[a][1];
				ir = a;
			}
		}
	}
	else{
		res = abs(tl - tr);
		for(int a=0;a<n;a++){
			if(res < abs((tl - s[a][0] + s[a][1]) - (tr - s[a][1] + s[a][0]))){
				res =  abs((tl - s[a][0] + s[a][1]) - (tr - s[a][1] + s[a][0]));
				ir = a;
			}
		}
	}
	printf("%d\n", ir+1);
}
