#include <bits/stdc++.h>
#define cout if (1) cout

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define pb push_back

struct vec {
	ll x, y;

	inline vec operator + (vec o) { return {x+o.x,y+o.y}; }
	inline vec operator - (vec o) { return {x-o.x,y-o.y}; }
	inline ll operator * (vec o) { return x*o.x + y*o.y; }
	inline ll operator ^ (vec o) { return x*o.y - y*o.x; }

	inline bool operator < (const vec & o) const {
		return (x!=o.x)?x<o.x:y>o.y;
	}
};
ostream& operator << (ostream & os, vec o) {
	return os << "(" << o.x << "," << o.y << ")" << endl;
}

inline bool compare (vec a, vec b) {
	vec o; o.x = o.y = 0;
	if ((a<o) != (b<o)) return (a<o);
	return (a^b) > 0;
}

const int N = 2e6+7;

int n;
vec v[N];

int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &v[i].x, &v[i].y);
		if (v[i].x == 0 && v[i].y == 0) {
			i--; n--;
		}
	}

	sort(v, v+n, [] (vec a, vec b) { return compare(a,b); });
	
	vec cur; cur.x = cur.y = 0;
	for (int i = 0; i < n; i++)
		v[i+n] = v[i];
	int r = 0;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		while (r < i+n && ((v[i]^v[r])?((v[i]^v[r])>0):(v[i]*v[r]>=0))) {
			cur = cur + v[r++];
			res = max(res, cur*cur);
		}
		res = max(res, cur*cur);
		cur = cur - v[i];
		res = max(res, cur*cur);
	}
	for (int i = 0; i < n; i++)
		v[i].x = -v[i].x;

	sort(v, v+n, [] (vec a, vec b) { return compare(a,b); });
	cur.x = cur.y = 0;
	for (int i = 0; i < n; i++)
		v[i+n] = v[i];
	r = 0;
	for (int i = 0; i < n; i++) {
		while (r < i+n && ((v[i]^v[r])?((v[i]^v[r])>0):(v[i]*v[r]>=0))) {
			cur = cur + v[r++];
			res = max(res, cur*cur);
		}
		res = max(res, cur*cur);
		cur = cur - v[i];
		//res = max(res, cur*cur);
	}

	printf("%lld\n", res);
}
