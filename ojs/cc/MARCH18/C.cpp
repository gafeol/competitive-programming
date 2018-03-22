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
ll sum[MAXN];
int res[MAXN], ans[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			res[a] = 0;
			scanf("%lld", s+a);
			if(a > 0)
				sum[a] = sum[a-1];
			else
				sum[a] = 0;
			sum[a] += s[a];
		}
		for(int a=0;a<n;a++){
			int i = a;
			int j = n-1;
			while(i < j){
				int m = (i + j + 1)/2;
				if(sum[m] - sum[a] - s[m] <= s[a])
					i = m;
				else
					j = m-1;
			}
			res[a+1]++;
			res[i+1]--;
			if(a > 0){
				i = 0;
				j = a-1;
				while(i < j){
					int m = (i + j)/2;
					ll ant = 0;
					if(m > 0) ant = sum[m-1];
					if(sum[a] - ant - s[a] - s[m] <= s[a])
						j = m;
					else
						i = m+1;
				}
				res[i]++;
				res[a]--;
			}
		}
		ans[0] = res[0];
		printf("%d ", ans[0]);
		for(int a=1;a<n;a++){
			ans[a] = ans[a-1] + res[a];
			printf("%d ", ans[a]);
		}
		puts("");
	}
}

