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
int ult[MAXN];
int v[MAXN];


bool test(int i){
	memset(ult, -1, sizeof(ult));
	for(int a=1;a<=i;a++){
		if(s[a] == 0)
			continue;
		ult[s[a]] = a;
	}
	for(int a=1;a<=m;a++){
		if(ult[a] == -1)
			return false;
	}
	int cnt = 0;
	for(int a=1;a<=i;a++){
		if(s[a] == 0){
			cnt++;
			continue;
		}
		if(ult[s[a]] == a){
			if(cnt < v[s[a]])
				return false;
			else
				cnt -= v[s[a]];
		}
		else
			cnt++;
	}
	return true;
}

int mrk[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	memset(mrk, -1, sizeof(mrk));
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		mrk[s[a]] = a;
	}
	for(int a=1;a<=m;a++){
		scanf("%d", &v[a]);
	}
	for(int a=1;a<=m;a++){
		if(mrk[a] == -1){
			puts("-1");
			return 0;
		}
	}
	int i = 1, j = n;
	if(!test(n)){
		puts("-1");
		return 0;
	}
	while(i < j){
		int m = (i+j)/2;
		if(test(m))
			j = m;
		else
			i = m+1;
	}
	printf("%d\n", i);
	
}
