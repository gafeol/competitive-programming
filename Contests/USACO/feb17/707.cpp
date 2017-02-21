

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
int s[MAXN];
int mrk[MAXN], bit[MAXN];

void upd(int i, int val){
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

int qry(int i){
	int res = 0;
	while(i > 0){
		res += bit[i];
		i -= (i&-i);
	}
	return res;
}

int main (){
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	scanf("%d", &n);
	int res =0;
	for(int a=1;a<=2*n;a++){
		scanf("%d", &s[a]);		
		if(mrk[s[a]] != 0){
			res += qry(a) - qry(mrk[s[a]]);
			upd(mrk[s[a]], -2);
			upd(a, 1);
		}
		else
			upd(a, 1);
		mrk[s[a]] = a;
	}
	printf("%d", res/2);
}
