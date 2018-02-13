
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

ll t;

pii s[MAXN];
int ind[MAXN];

bool cmp(int a, int b){
	return s[a].snd < s[b].snd;
}

int go(int m){
	ll res = t;
	int cnt = 0;
	for(int ii=0;ii<n;ii++){
		int i = ind[ii];
		if(s[i].fst < m || s[i].snd > res) continue;
		res -= s[i].snd;
		cnt++;
	}
	return (cnt >= m);
}

vector<int> ans;

void print(int m){
	ll res = t;
	int cnt = 0;
	for(int ii=0;ii<n;ii++){
		int i = ind[ii];
		if(s[i].fst < m || s[i].snd > res) continue;
		res -= s[i].snd;
		if(cnt < m){
			ans.pb(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i=0;i<ans.size();i++){
		printf("%d ", ans[i]+1);
	}
	puts("");
}

int main (){
	scanf("%d%lld", &n, &t);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
		ind[a] = a;
	}
	sort(ind, ind+n, cmp);
	int i = 0, j = n;
	while(i < j){
		int m = (i + j + 1)/2;
		if(go(m))
			i = m;
		else
			j = m-1;
	}
	printf("%d\n", i);
	print(i);
}

