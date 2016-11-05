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
int na[MAXN], cs[MAXN];
ll s[MAXN], c[MAXN], ind[MAXN];
int adap, comp;

map<int, stack<int> > mrk;

bool cmp(int a, int b){
	return s[a] < s[b];
}

bool cmp2(int a, int b){
	return a<b;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		cs[a] = 0;
		scanf("%lld", &c[a]);
		mrk[c[a]].push(a);
	}
	for(int a=1;a<=m;a++){
		ind[a] = a;
		scanf("%lld", &s[a]);
		na[a] = -1;
	}
	sort(ind+1, ind+m+1, cmp);
	sort(s+1, s+m+1, cmp2);
	for(int a=1;a<=m;a++){
		int cnt = 0;
		while(s[a] > 1){
			if(mrk.find(s[a]) != mrk.end() && mrk[s[a]].size() != 0){
				int t = mrk[s[a]].top();
				mrk[s[a]].pop();
				cs[t] = ind[a];
				na[ind[a]] = cnt;
				comp++;
				adap+=cnt;
				break;
			}
			cnt++;
			s[a] = (s[a]+1)/2;
		}
		if(na[ind[a]] == -1){
			if(mrk.find(s[a]) != mrk.end() && mrk[s[a]].size() != 0){
				int t = mrk[s[a]].top();
				mrk[s[a]].pop();
				cs[t] = ind[a];
				na[ind[a]] = cnt;
				comp++;
				adap+=cnt;
			}
		}
		if(na[ind[a]] == -1)
			na[ind[a]] = 0;
	}
	printf("%d %d\n", comp, adap);
	for(int a=1;a<=m;a++){
		printf("%d ", na[a]);
	}
	putchar('\n');
	for(int a=1;a<=n;a++){
		printf("%d ", cs[a]);
	}

}
