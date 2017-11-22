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
int s[MAXN], ind[MAXN];

map<int,int> mrk;

bool cmp(int a, int b){
	return s[a] < s[b];
}

int res[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(mrk.find(s[a]) != mrk.end()){
			puts("-1");
			return 0;
		}
		mrk[s[a]]++;
		ind[a] = a;
	}
	if(n == 1){
		printf("%d\n", s[0]);
		return 0;
	}
	sort(ind, ind + n, cmp);
	int first = -1;
	for(int a=0;a<n-1;a++){
		int i = ind[a];
		int j = ind[a+1];
		res[i] = s[j];
		if(first == -1)
			first = s[i];
	}
	res[ind[n-1]] = first;
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
	puts("");
}

