#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 100010;

long double EPS = 1e-9;

int n;

typedef long long ll;

typedef pair<ll, ll> pll;
#define fst first
#define snd second

pll s[MAXN];

bool go(long double y){
	long double mn = DBL_MIN, mx = DBL_MAX;
	for(int a=0;a<n;a++){
		long double dy = abs(y - s[a].snd);
		if(y < dy)
			return false;
		long double dx = abs(sqrt(y - dy)*sqrt(y + dy));
		mn = max(mn, s[a].fst - dx); 
		mx = min(mx, s[a].fst + dx);
	}
	return (mn <= mx);
}

int main (){
	clock_t clk = clock();
	scanf("%d", &n);
	ll mn = 0, mx = 0;
	for(int a=0;a<n;a++){
		ll i, j;
		scanf("%lld%lld", &i, &j);
		s[a] = pll(i, j);
		mn = min(mn, s[a].snd);
		mx = max(mx, s[a].snd);
	}
	if(mn < 0 && mx > 0){
		puts("-1");
		return 0;
	}
	if(mn < 0){
		for(int a=0;a<n;a++)
			s[a].snd *= -1;
	}
	long double i = 0, j = 1e15+10.;
	while(abs(j-i) > 1e-9 && ((long double)clock() - clk)/CLOCKS_PER_SEC < 1.8){
		long double m = (i + j)/2.;
		if(go(m)){
			j = m;
		}
		else{
			i = m;
		}
	}
	long double ans = (i + j)/2.;
	if(ans > 1e15)
		puts("-1");
	else
		printf("%.10lf\n", (i+j)/2.);
}

