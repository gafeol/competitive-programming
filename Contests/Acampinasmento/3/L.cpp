#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> toA(ll a, int n) {
	int p = n;
	ll t = 1ll;
	while (--p) {
		t *= 10;
	}
	vector<int> res;
	while (t) {
		res.push_back((a/t)%10);
		t /= 10ll;
	}
	return res;
}

ll toL(vector<int> v, int n) {
	ll a = 0;
	for (int i=n-1;i>=0;i--) {
		a *= 10;
		a += v[i];
	}
	return a;
}

vector<int> swapA(vector<int> v, int n) {
	vector<int> s;
	for (int i=n-1;i>=0;i--) {
		s.push_back(v[i]);
	}
	return s;
}

vector<int> makeMx(int a, int n) {
	vector<int> res;
	while (a) {
		res.push_back(min(a, 9));
		a -= min(a, 9);
	}
	while (res.size() != n) {
		res.push_back(0);
	}
	return res;
}

ll po(int n) {
	ll p = n;
	ll t = 1ll;
	while (--p) {
		t *= 10;
	}
	return t;
}

void print(vector<int> v) {
	for (int i=0;i<v.size();i++) printf("%d", v[i]);
}

ll val[5000][5];

int main () {
	int n; scanf("%d", &n);
	for (int i=1;i<=9*n;i++) {
		val[i][0] = toL(makeMx(i, n), n);
		val[i][1] = toL(swapA(makeMx(i, n), n), n);
		//printf("%lld %lld\n", val[i][0], val[i][1]);
	}
	ll mx = -1;
	int id = 0; 
	ll t = po(n)*10ll;
	for (int i=1;i<9*n;i++) {
		ll dif = t - val[i][1];
		dif += val[i+1][0];
		//printf("%d %lld (%lld %lld %lld)\n", i, dif, t, val[i][1], val[i+1][0]);
		if (dif > mx) {
			mx = dif;
			id = i;
		}
	}
	//printf("%d %lld\n", id, mx);
	print(toA(val[id][1], n));print(toA(val[id][1]+1, n));printf("\n");
	print(toA(val[id][1]+1, n));print(toA(val[id+1][0]-1, n));printf("\n");
	return 0;
}
