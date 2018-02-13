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

const int N = 0, A = 1, O = 2;
const int MAXN = 3*262, INF = 0x3f3f3f3f;

int n, m, k;
char s[10];

int d[MAXN];

string st[MAXN];

int id(int u, int t){
	return u*3 + t;
}

void init(){
	for(int a=0;a<MAXN;a++){
		d[a] = INF;
		st[a] = "";
	}
}

void add(int u, string e){
	d[u] = e.size();
	st[u] = e;
	q.insert(pii(d[u], u));
}

vector<int> vis;

int cus(int u, int t){
	int bm = u
}

int main (){
	init();

	add(id(15, N), "x");
	add(id(51, N), "y");
	add(id(85, N), "z");
	while(!q.empty()){
		pii top = *q.begin();
		int u = top.snd;
		int bm = u/3;
		int t = (u%3);
		test(neg(u), cus(u, N)); 
		vis.pb(u);
	}

	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s);
		int u = 0;
		for(int a=0;a<8;a++){

		}
	}
}

