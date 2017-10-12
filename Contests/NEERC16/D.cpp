
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fst first
#define snd second
#define pb push_back

const int MAXN = 212345;


int n;

ll t;

ll s[MAXN], tf[MAXN];

ll pos, sob;

int main(){
	scanf("%d %lld", &n, &t);
//	t *= 2ll;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
//		s[a] *= 2ll;
	}

	int ok = 1;
	for(int a=0;a<n;a++){
		scanf("%lld", tf+a);
//		tf[a] *= 2ll;
		if(tf[a] < s[a]) ok = 0;
	}
	if(!ok){
		puts("-1");
		return 0;
	}
	ll res = 0;
	sob = 0;	
	ll ti = 0;
	for(int i=0;i<n;i++){
		ti = 0;
		ll d = s[i];
		if(d <= sob){
			sob -= d;
			continue;
		}
		d -= sob;
		ti += sob;
		sob = 0;
		ll da = min(d, tf[i] - ti - d);
		ll pot = (d - da)/t + ((d - da)%t != 0);
		res += pot;
		if((d - da)%t != 0)
			sob = t - ((d - da)%t);
	}
	printf("%lld\n", res);
	if(res <= 100000){
		ll tempo = 0;
		sob = 0;
		for(int i=0;i<n;i++){
			ti = 0;
			ll d = s[i];
			if(d <= sob){
				sob -= d;
				continue;
			}
			d -= sob;
			ti += sob;
			sob = 0;
			ll da = min(d, tf[i] - ti - d);
			tempo += da*2ll;

			ll pot = (d - da)/t + ((d - da)%t != 0);
			int cnt = 0;
			while(cnt < pot){
				printf("%lld ", tempo);
				tempo += t;
				cnt++;
			}
			res += pot;
			if((d - da)%t != 0)
				sob = t - ((d - da)%t);
		}
	}
	puts("");
}
