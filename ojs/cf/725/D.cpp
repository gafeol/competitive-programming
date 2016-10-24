#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
ll b[MAXN], w[MAXN];

int ind[MAXN];

struct team{
	ll b, w;
	bool operator < (team o) {
		return (b > o.b || (b == o.b && w > o.w));
	}
} s[MAXN];

bool cmp(team a, team o){
	return (a.w -a.b < o.w-o.b);
}

vector<team> win, los;

ll nb;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a].b, &s[a].w);
		if(a !=0){
			if(s[a].b <= s[0].b)
				los.pb(s[a]);
			else
				win.pb(s[a]);
		}
	}
	sort(los.begin(), los.end());
	sort(win.begin(), win.end(), cmp);
	int res = win.size()+1;
	ll nb = s[0].b;
	int i=0, j=0;
	while(nb > 0){
		res = min(res, (int)win.size() - i);
		if(res == 0) break;
		nb -= win[i].w - win[i].b + 1;
		while(j < los.size() && los[j].b > nb){
			nb -= los[j].w - los[j].b + 1;
			j++;
		}
		i++;
	}
	printf("%d\n", res);
}
