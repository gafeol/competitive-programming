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
ll s[MAXN], cnt[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	sort(s, s+n);
	for(int i =0;i < 3;i++){
		for(int a=0;a<n;a++){
			if(s[a] == s[i])
				cnt[i]++;
		}
	}
	if(s[0] == s[2]){
		printf("%lld\n", (cnt[0]*(cnt[0]-1)*(cnt[0]-2))/6);
	}
	else if(s[0] == s[1]){
		printf("%lld\n", ((cnt[0]*(cnt[0]-1))/2)*cnt[2]);
	}
	else if(s[2] == s[1]){
		printf("%lld\n", ((cnt[1]*(cnt[1]-1))/2)*cnt[0]);
	}
	else{
		printf("%lld\n", cnt[0]*cnt[1]*cnt[2]);
	}
}