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


map<int,int> mrk;

int n, m;
int s[MAXN];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

void EE(int a, int b, int& x, int& y){
	if(a%b == 0)
	{
		x=0;
		y=1;
		return;
	}
	EE(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp - y*(a/b);
}

int inverse(int a, int k){
	int x,y;
	EE(a,k,x,y);
	if(x<0) x += k;
	return x;
}
vector<int> res;
vector<int> cp, rest;
vector<int> gcds;

vector<int> cnt[MAXN];

int steps(int i, int j, int mult){
	int aux = 0;
	int mul = 1;
	while(i != j){
		mul = (mul*mult)%m;
		i = (i*mul)%m;
	}
	return mul;
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		mrk[s[a]] = -1;
	}
	sort(s, s+n);
	int i = 0;
	for(int j=1;j<m;j++){
		while(i < n  && j > s[i])
			i++;
		if(j == s[i])
			continue;
		if(gcd(j, m) == 1)
			cp.pb(j);
		else{
			if(cnt[gcd(j, m)].empty())
				gcds.pb(gcd(j, m));
			cnt[gcd(j, m)].pb(j);
			debug("adiciona na conta %d no gcd %d\n", j, gcd(j, m));
		}
	}
	int bef = 1;
	for(int co: cp){
		debug("cop %d\n", co);
		res.pb((co*inverse(bef, m))%m);
		bef = co;
	}
	int mx = -1, imx = -1;
	for(int op: gcds){
		if((int)cnt[op].size() > mx){
			mx = (int)cnt[op].size();
			imx = op;
		}
	}
	debug("best gcd %d com %d\n", imx, mx);
	if(mx != -1){
		mrk[cnt[imx][0]] = 1;
		res.pb((cnt[imx][0]*inverse(bef, m))%m);
		int val = (cnt[imx][0]*imx)%m;
		while(mrk[val] != 1){
			debug("to em val %d\n", val);
			ll pt = 1;
			while(mrk[(val*pt)%m] == -1)
				pt *= imx;
			if(mrk[(val*pt)%m] == 1)
				break;
			res.pb((pt*imx)%m);
			mrk[(val*pt)%m] = 1;
			val = (val*pt*imx)%m;

		}
	}
	if(n == 0 || s[0] != 0){
		res.pb(0);
	}
	printf("%d\n", (int)res.size());
	for(int val: res){
		printf("%d ", val);
	}
}
