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

const int MAXN = 212345, BIT = (1<<21) + 10;

int n, m, k;

int s[MAXN];
int mrk[MAXN];

ll cnt[2][BIT];

ll qtd[73];

int pri[73][22];

ll pot[MAXN];

ll res;
vector<int> p;

void f(int i){
	int ii = i;
	for(int ip =0;ip < p.size();ip++){
		int pr = p[ip];
		while(ii%pr == 0){
			pri[i][ip]++;
			ii/=pr;
		}
	}
}

int ac(int i){
	int c = 0;
	for(int a=0;a<21;a++){
		if((pri[i][a]&1))
			c ^= (1<<a);
	}
	return c;
}

int main (){
	for(int a=2;a<=70;a++){
		if(mrk[a]) continue;
		p.pb(a);
		for(int b=a;b*a <= 70;b++){
			mrk[b*a] = 1;
		}
	}
	for(int a=1;a<=70;a++){
		f(a);
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		int bm = ac(s[a]);
		qtd[bm]++;
	}
	pot[0] =1;
	for(int a=1;a<=n;a++){
		pot[a] = mod(2ll*pot[a-1]);
	}
	int t = 0;
	cnt[0][0] = 1;
	for(int i=0;i<=70;i++){
		if(qtd[i] == 0) continue;
		int bm = i;
		for(int a=0;a<BIT;a++)
			cnt[t^1][a] = 0;
		for(int a=0;a<BIT;a++){
			if(cnt[t][a] != 0){
				ll old = cnt[t][a];
				ll old2 = cnt[t^1][a^bm];
				cnt[t^1][a] = mod(cnt[t^1][a] + cnt[t][a]*pot[qtd[i]-1]);
				cnt[t^1][a^bm] = mod(cnt[t^1][a^bm] + old*pot[qtd[i]-1]);
			}
		}
		for(int a=0;a<BIT;a++)
			cnt[t^1][a] = mod(cnt[t^1][a] + cnt[t][a]);
		/*for(int a=0;a<10;a++)
			debug("%d ", cnt[t^1][a]);
		debug("\n");*/
		t = t^1;
	}
	printf("%lld\n", mod(modn + mod(cnt[(t&1)][0]-1)));
}

