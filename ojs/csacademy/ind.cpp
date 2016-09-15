#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

pii s[MAXN], mx[MAXN];
int nxt[MAXN];


bool cmp(pii a, pii b){
	return (a.fst < b.fst || (a.fst == b.fst && a.snd > b.snd));
}

bool men(pii a, pii b){
	return a.fst < b.fst && a.snd < b.snd;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i , j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
	}
	sort(s, s+n, cmp);
	int ult = n;
	mx[n] = pii(-1, -1);
	for(int a=n-1;a>=0;a--){
		if(s[a].fst != s[a+1].fst)
			ult = a+1;
		nxt[a] = ult;
		mx[a] = mx[a+1];
		if(mx[a+1].snd < s[a].snd)
			mx[a] = s[a];
	}
	int res = 0;
	for(int a=0;a<n;a++){
		if(!men(s[a], mx[nxt[a]]))
			res++;
	}
	printf("%d\n", res);
}
