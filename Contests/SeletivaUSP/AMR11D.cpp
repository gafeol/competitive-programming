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

const int MAXN = 55;

int n, m, k;
int s[MAXN], w[MAXN];

bool cmp(int a, int b){
	return a > b;
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			w[a] = 0;
		}
		sort(s, s+n, cmp);
		int res = 0;
		for(int a=0;a<n;a++){
			int i = a+1, j = n-1;
			while(i <= j){
				if(w[a] < s[a]){
					w[a]++;
					j--;
				}
				else{
					w[i]++;
					i++;
				}
			}
			res += abs(s[a] - w[a]);

		}
		printf("%d\n", res);
	}
}
