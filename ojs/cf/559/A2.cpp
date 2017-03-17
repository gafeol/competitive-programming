
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

int main (){
	n = 6;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}

	int res = 0;
	int cnt = s[0]*2 + 1;
	int i = 1, j = 5;
	while(i < 3 && j > 3){
		res += cnt;
		debug("soma %d\n", cnt);
		if(i&1)
			cnt++;
		else
			cnt--;
		if(j&1) 
			cnt++;
		else
			cnt--;
		s[i]--;
		s[j]--;
		if(s[i] == 0){
			i++;
			cnt--;
		}
		if(s[j] == 0){
			j--;
			cnt--;
		}
	}
	printf("%d\n", res);
}

