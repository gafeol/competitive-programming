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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<int> p;

inline void r(int x){
	if(x == -1)
		exit(0);
}

int prob[MAXN];

bool cmp(int a, int b){
	return prob[a] < prob[b];
}

int main (){
	srand(time(NULL));
	for_tests(t, tt){
		debug("test %d\n", tt);
		scanf("%d", &n);
		for(int a=0;a<=n;a++){
			s[a] = 0;
			prob[a] = 0;
		}
		for(int a=0;a<n;a++){
			scanf("%d", &m);
			r(m);
			p.clear();
			for(int b=0;b<m;b++){
				int l;
				scanf("%d", &l);
				r(l);
				prob[l]++;
				if(!s[l])
					p.pb(l);
			}
			if(p.empty()){
				puts("-1");
				fflush(stdout);
				debug("cannot sell to %d-th\n", a);
			}
			else{
				sort(p.begin(), p.end(), cmp);
				int cnt = 1;
				for(cnt=1;cnt<p.size();cnt++){
					if(prob[p[cnt]] != prob[p[cnt-1]])
						break;
				}
				int i = rand()%cnt;
				debug("rand from %d\n", cnt);
				printf("%d\n", p[i]);
				fflush(stdout);
				debug("sell %d to %d-th\n", p[i], a);
				s[p[i]] = 1;
			}
		}
	}
}

