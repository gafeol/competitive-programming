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

int pre[MAXN], aft[MAXN];

int pr[2][MAXN], af[2][MAXN];
int rvp[MAXN], rva[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	int res = 1;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=i+1;j<n;j++){
			if(s[j] < s[j-1])
				cnt++;
			if(cnt <= 1)
				res = max(res, j - i + 1);
			else
				break;
		}
	}

	for(int i=0;i<n;i++){
		pre[i] = 1;
		int j = i;
		while(j + 1 < n && s[j+1] >= s[j]){
			pre[i]++;
			j++;
		}
	}
	debug("rvp\n");
	for(int i=0;i<n;i++){
		rvp[i] = 1;
		int j = i;
		while(j+1 < n && s[j+1] <= s[j]){
			rvp[i]++;
			j++;
		}
		debug("%d ", rvp[i]);
	}
	debug("\n");
	for(int j=n-1;j>=0;j--){
		aft[j] = 1;
		int i = j;
		while(i-1 >= 0 && s[i-1] <= s[i]){
			aft[j]++;
			i--;
		}
	}
	debug("rva\n");
	for(int i=0;i<n;i++){
		rva[i] = 1;
		int j = i;
		while(j -1 >=0 && s[j-1] >= s[j]){
			rva[i]++;
			j--;
		}
		debug("%d ", rva[i]);
	}
	debug("\n");
	for(int i=0;i<n;i++){
		int cnt = 0;
		int ok = 1;
		int j = i;
		while(j < n){
			if(s[j] != 1) ok = 0;
			if(ok) cnt++;
			res = max(res, pre[j+1]+cnt);
			j++;
		}
	}
	for(int i=0;i<n;i++){
		int cnt = 0;
		int ok = 1;
		int j = i;
		while(j >= 0){
			if(s[j] != 2) ok = 0;
			if(ok) cnt++;
			if(j == 0)
				res = max(res, cnt);
			else
				res = max(res, aft[j-1]+cnt);
			j--;
		}
	}
	for(int t=1;t<=2;t++){
		for(int i=0;i<n;i++){
			pr[t][i] = 0;
			int j = i;
			while(j < n){
				if(s[j] != t) break;
				pr[t][i]++;
				j++;
			}
		}
	}
	for(int t=1;t<=2;t++){
		for(int i=0;i<n;i++){
			af[t][i] = 0;
			int j = i;
			while(j >= 0){
				if(s[j] != t) break;
				af[t][i]++;
				j--;
			}
		}
	}
	
	// REVERSE
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int tam = j - i + 1;
			if(i > 0) res = max(res, min(rva[j], tam) + af[1][i-1]);
			else      res = max(res, min(rva[j], tam));
			res = max(res, min(rvp[i], tam) + pr[2][j+1]);
		}
	}
	printf("%d\n", res);
}

