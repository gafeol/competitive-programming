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
ll s[MAXN];
ll v[MAXN];

map<ll, int> mrk;

int main (){
	scanf("%d", &n);
	mrk[0]++;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		v[n-a-1] = s[a];
	}
	int i = -1, j = n;
	ll pre = 0, suf = 0;
	for(;j > 0 ;j--){
		suf += s[j-1];
		mrk[s[j-1]]++;
	}
	if((suf - pre)%2 == 0 && mrk[(suf - pre)/2] > 0){
		debug("move o %lld i %d pre %lld j %d suf %lld\n", (suf - pre)/2, i, pre, j, suf); 
		puts("YES");
		return 0;
	}
	while(i < n - 1){
		pre += s[i+1];	
		i++;
		while(j <= i){
			suf -= s[j];
			mrk[s[j]]--;
			j++;
		}
		debug("i %d pref %lld j %d suf %lld\n", i, pre, j, suf);
		if((suf - pre)%2 == 0 && mrk[(suf - pre)/2] > 0){
			debug("move o %lld i %d pre %lld j %d suf %lld\n", (suf - pre)/2, i, pre, j, suf); 
			puts("YES");
			return 0;
		}
	}
	mrk.clear();
	mrk[0]++;
	for(int a=0;a<n;a++){
		s[a] = v[a];
	}
	i = -1;
	j = n;
	pre = 0;
	suf = 0;
	for(;j > 0 ;j--){
		suf += s[j-1];
		mrk[s[j-1]]++;
	}
	if((suf - pre)%2 == 0 && mrk[(suf - pre)/2] > 0){
		debug("move o %lld i %d pre %lld j %d suf %lld\n", (suf - pre)/2, i, pre, j, suf); 
		puts("YES");
		return 0;
	}
	while(i < n - 1){
		pre += s[i+1];	
		i++;
		while(j <= i){
			suf -= s[j];
			mrk[s[j]]--;
			j++;
		}
		debug("i %d pref %lld j %d suf %lld\n", i, pre, j, suf);
		if((suf - pre)%2 == 0 && mrk[(suf - pre)/2] > 0){
			debug("move o %lld i %d pre %lld j %d suf %lld\n", (suf - pre)/2, i, pre, j, suf); 
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}
