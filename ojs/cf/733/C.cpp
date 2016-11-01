#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#define debug(args...) //fprintf(stderr,args)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512;

int n, m, k;
int s[MAXN], v[MAXN], fodeu = 0;

vector<pii> res;

set<pii> ord;

bool cmp(pii a, pii b){
	return a.fst > b.fst;
}

main (){
	scanf("%lld", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
	}
	scanf("%lld", &k);
	int b =0;
	int cor = -1, ncor = 0;
	for(int a=0;a<k;a++){
		scanf("%lld", &v[a]); 
		if(fodeu) continue;
		int som = 0;
		int ini = b;
		int mx = LLONG_MIN;
		for(;b < n && som < v[a];b++){
			som += s[b];
			mx = max(mx, s[b]);
		}
		if(som != v[a]){
			fodeu = 1;
			continue;
		}
		if(ini == b-1)
			continue;
		int im=-1;
		for(int c=ini;c<b;c++){
			if(s[c] != mx) continue;
			if(c == ini){
				if(s[c+1] < mx){
					im = c;
					break;
				}
			}
			else if(c == b-1){
				if(s[c-1] < mx){
					im = c;
					break;
				}
			}
			else{
				if(s[c-1] < mx || s[c+1] < mx){
					im = c;
					break;
				}
			}
		}
		if(im == -1){
			fodeu = 1;
			continue;
		}
		debug("%lld im %lld\n", a, im);
		int i = im, j = im;
		while(i != ini || j != b-1){
			if(i > ini && s[i-1] < s[im]){
				s[im] += s[i-1];
				res.pb(pii(0, im-cor));
				cor++;
				i--;
			}
			else if(j < b-1 && s[j+1] < s[im]){
				s[im] += s[j+1];
				res.pb(pii(1, im-cor));
				ncor++;
				j++;
			}
			else{
				fodeu = 1;
				break;
			}
		}
		if(fodeu)
			continue;
		cor += ncor;
		ncor=0;
	}
	if(b != n)
		fodeu = 1;
	if(fodeu)
		puts("NO");
	else{
		puts("YES");
		for(pii x: res){
			printf("%lld ", x.snd);
			if(!x.fst)
				puts("L");
			else
				puts("R");
		}
	}
}
