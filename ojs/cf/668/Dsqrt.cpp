#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

const int MAXN = 212345, RAIZ = 412;

#define tp snd.snd
#define tt fst
#define xx snd.fst

int n, m, k;
pip q[MAXN];

int s[MAXN];

map<int, int> sum[RAIZ];

vector<int> cmp;

int main (){
	scanf("%d", &n);
	int sq = sqrt(n)+1;
	for(int a=0;a<n;a++){
		scanf("%d %d %d", &q[a].tp, &q[a].tt, &q[a].xx);
		cmp.pb(q[a].tt);
	}
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

	for(int a=0;a<n;a++){
		int t = lower_bound(cmp.begin(), cmp.end(), q[a].tt) - cmp.begin();
		if(q[a].tp == 1){
			s[t] = q[a].xx;
			sum[t/sq][q[a].xx]++;
		}
		else if(q[a].tp == 2){
			s[t] = -q[a].xx;
			sum[t/sq][q[a].xx]--;
		}
		else{
			int cnt = 0;
			int i;
			for(i=0;(i+1)*sq-1 <= t;i++){
				if(sum[i].find(q[a].xx) != sum[i].end()){
					cnt += sum[i][q[a].xx];
				}
			}
			for(int b=i*sq;b<=t;b++){
				cnt += (s[b] == q[a].xx) - (s[b] == -q[a].xx);
			}
			printf("%d\n", cnt);
		}	
	}
}
