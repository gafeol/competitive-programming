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

const int MAXN = 1023456;

int s[MAXN];
int n, seq[MAXN], mai, tree[MAXN];

ll bit(int i){
	i+= 2;
	ll res =0;
	while(i>0){
		res+=tree[i];
		i-=(i&-i);
	}
	return res;
}

void upd(int i){
	while(i< MAXN){
		tree[i]+=1;
		i+=(i&-i);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &seq[a]);
	}
	ll ans = 0;
	for(int a=n-1;a>=0;a--){
		ans += bit(seq[a]);
		upd(seq[a]);
	}
	if(ans%2 == 0)
		puts("Um_nik");
	else
		puts("Petr");
	return 0;
}
